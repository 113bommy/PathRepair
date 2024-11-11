#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int INF = 1e7;
int arr[N];
int freq[N];
int n, s, id;
int dp[N][2];
int dist[N][N][2];
bool printed[N];
int moveIdx(int idx1, int idx2, bool right) {
  int &ret = dist[idx1][idx2][right];
  if (~ret) return ret;
  if (idx1 == idx2) return 0;
  if (right)
    return ret = moveIdx((idx1 + 1) % n, idx2, right) + 1;
  else
    return ret = moveIdx((idx1 - 1 + n) % n, idx2, right) + 1;
}
int solve(int idx, bool moveIdxNext) {
  if (moveIdxNext && arr[idx] == id) return 0;
  int &ans = dp[idx][moveIdxNext];
  if (~ans) return ans;
  ans = INF;
  if (moveIdxNext) {
    for (int i = 0; i < n; i++) {
      if (arr[i] == arr[idx] + 1)
        ans =
            min(ans, min(moveIdx(idx, i, 1), moveIdx(idx, i, 0)) + solve(i, 0));
    }
    return ans;
  }
  if (freq[arr[idx]] == 1) return ans = solve(idx, 1);
  int ptr1 = idx, ptr2;
  for (int i = (idx - 1 + n) % n; i != idx; i = (i - 1 + n) % n) {
    if (arr[i] == arr[idx]) ptr2 = i;
  }
  while (ptr2 != idx) {
    ans = min(ans,
              moveIdx(idx, ptr1, 1) + moveIdx(ptr1, ptr2, 0) + solve(ptr2, 1));
    ptr1 = ptr2;
    for (int i = (ptr2 + 1) % n;; i = (i + 1) % n) {
      if (arr[i] == arr[idx]) {
        ptr2 = i;
        break;
      }
    }
  }
  ans = min(ans, moveIdx(idx, ptr1, 1) + solve(ptr1, 1));
  return ans;
}
void output(int idx, bool moveIdxNext) {
  if (moveIdxNext && arr[idx] == id) return;
  int &ans = dp[idx][moveIdxNext];
  if (moveIdxNext) {
    for (int i = 0; i < n; i++) {
      if (arr[i] == arr[idx] + 1 &&
          ans == min(moveIdx(idx, i, 1), moveIdx(idx, i, 0)) + solve(i, 0)) {
        int p1 = moveIdx(idx, i, 1);
        int p2 = moveIdx(idx, i, 0);
        printed[i] = 1;
        if (p1 <= p2) {
          printed[i] = 1;
          cout << "+ " << p1 << '\n';
        } else {
          printed[p2] = 1;
          cout << "- " << p2 << '\n';
        }
        return output(i, 0);
      }
    }
  }
  if (freq[arr[idx]] == 1) return output(idx, 1);
  int ptr1 = idx, ptr2;
  for (int i = (idx - 1 + n) % n; i != idx; i = (i - 1 + n) % n) {
    if (arr[i] == arr[idx]) ptr2 = i;
  }
  while (ptr2 != idx) {
    if (ans ==
        moveIdx(idx, ptr1, 1) + moveIdx(ptr1, ptr2, 0) + solve(ptr2, 1)) {
      int prev = idx;
      if (ptr1 != idx) {
        for (int i = (idx + 1) % n; i != ptr1; i = (i + 1) % n) {
          if (arr[i] != arr[idx] || printed[i]) continue;
          printed[i] = 1;
          cout << "+ " << moveIdx(prev, i, 1) << '\n';
          prev = i;
        }
        if (!printed[ptr1]) {
          printed[ptr1] = 1;
          cout << "+ " << moveIdx(prev, ptr1, 1) << '\n';
        }
      }
      prev = ptr1;
      for (int i = (ptr1 - 1 + n) % n; i != ptr2; i = (i - 1 + n) % n) {
        if (arr[i] != arr[idx] || printed[i]) continue;
        printed[i] = 1;
        cout << "- " << moveIdx(prev, i, 0) << '\n';
        prev = i;
      }
      if (!printed[ptr2]) {
        printed[ptr2] = 1;
        cout << "- " << moveIdx(prev, ptr2, 0) << '\n';
      }
      return output(ptr2, 1);
    }
    ptr1 = ptr2;
    for (int i = (ptr2 + 1) % n;; i = (i + 1) % n) {
      if (arr[i] == arr[idx]) {
        ptr2 = i;
        break;
      }
    }
  }
  int prev = idx;
  for (int i = (idx + 1) % n; i != ptr1; i = (i + 1) % n) {
    if (arr[i] != arr[idx] || printed[i]) continue;
    printed[i] = 1;
    cout << "+ " << moveIdx(prev, i, 1) << '\n';
    prev = i;
  }
  if (!printed[ptr1]) {
    printed[ptr1] = 1;
    cout << "+ " << moveIdx(prev, ptr1, 1) << '\n';
  }
  return output(ptr1, 1);
}
void input() {
  cin >> n >> s;
  s--;
  set<int> sett;
  map<int, int> mapping;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sett.insert(arr[i]);
  }
  for (int num : sett) {
    mapping[num] = id++;
  }
  id--;
  for (int i = 0; i < n; i++) {
    arr[i] = mapping[arr[i]];
    freq[arr[i]]++;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  input();
  memset(dist, -1, sizeof dist);
  memset(dp, -1, sizeof dp);
  int ans = INF;
  for (int i = 0; i < n; i++) {
    if (arr[i] != 0) continue;
    ans = min(ans, min(moveIdx(s, i, 1), moveIdx(s, i, 0)) + solve(i, 0));
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    if (arr[i] != 0) continue;
    int cur = min(moveIdx(s, i, 1), moveIdx(s, i, 0)) + solve(i, 0);
    if (cur == ans) {
      printed[i] = 1;
      int p1 = moveIdx(s, i, 1);
      int p2 = moveIdx(s, i, 0);
      if (p1 <= p2)
        cout << "+ " << p1 << '\n';
      else
        cout << "- " << p2 << '\n';
      output(i, 0);
      return 0;
    }
  }
  return 0;
}
