#include <bits/stdc++.h>
using namespace std;
const int inf = 987654321;
const long long int INF = 123456789987654321;
int N;
vector<int> arr, fix;
vector<vector<int> > cache;
int dp(int idx, int bf) {
  int& ret = cache[idx][bf];
  if (ret != -1) return ret;
  ret = 0;
  if (idx == 0) {
    int a = fix[idx];
    int val = arr[a];
    if (a == 0 && arr[a] == 1 && bf)
      return ret = 1;
    else if (a == 0)
      return ret = 0;
    if (arr[a] == 1) {
      if (a + 1 <= 5 - bf)
        return ret = 1;
      else
        return ret = 0;
    }
    for (int i = max(1, 2 - bf); i <= 5 - bf; i++) {
      int idx2 = a - i;
      if (idx2 <= 0) break;
      if (val - 1 > idx2 / 2 + 1) continue;
      if (val - 1 < idx2 / 5 + 1) continue;
      return ret = 1;
    }
    return ret = 0;
  }
  int a = fix[idx], b = fix[idx - 1];
  int val = arr[a] - arr[b];
  if (val == 0) {
    if (a - b + 1 > 5 - bf) return ret = 0;
    return ret = dp(idx - 1, bf + a - b);
  }
  for (int i = max(1, 2 - bf); i <= 5 - bf; i++) {
    int c = a - i;
    if (c < b) break;
    if (val - 1 == 0) {
      if (c - b + 1 > 5) continue;
      ret |= dp(idx - 1, c - b);
    } else {
      for (int j = 1; j <= 5; j++) {
        int d = b + j;
        if (d + 1 > c) break;
        int diff = val - 2;
        if (diff > (c - d + 1) / 2 - 1) continue;
        if (diff < (c - d) / 5) continue;
        ret |= dp(idx - 1, j - 1);
      }
    }
  }
  return ret;
}
vector<int> ans;
void dfs(int idx, int bf) {
  if (idx == 0) {
    int a = fix[idx];
    int val = arr[a];
    if (a == 0 && arr[a] == 1 && bf) {
      ans.push_back(arr[a]);
      return;
    }
    if (arr[a] == 1) {
      if (a + 1 <= 5 - bf) {
        for (int i = 0; i <= a; i++) {
          ans.push_back(1);
        }
        return;
      }
    }
    for (int i = max(1, 2 - bf); i <= 5 - bf; i++) {
      int idx2 = a - i;
      if (idx2 < 0) break;
      if (val - 1 > idx2 / 2 + 1) continue;
      if (val - 1 < idx2 / 5 + 1) continue;
      int add = 0;
      for (int j = 0; j <= idx2; j++) {
        ans.push_back(add + 1);
        add = (add + 1) % (arr[a] - 1);
      }
      for (int j = 0; j < i; j++) {
        ans.push_back(arr[a]);
      }
      return;
    }
  }
  int a = fix[idx], b = fix[idx - 1];
  int val = arr[a] - arr[b];
  if (val == 0) {
    dfs(idx - 1, bf + a - b);
    for (int i = b + 1; i <= a; i++) {
      ans.push_back(arr[a]);
    }
    return;
  }
  for (int i = max(1, 2 - bf); i <= 5 - bf; i++) {
    int c = a - i;
    if (c < b) break;
    if (val - 1 == 0) {
      if (c - b + 1 > 5) continue;
      if (dp(idx - 1, c - b)) {
        dfs(idx - 1, c - b);
        for (int j = b + 1; j <= c; j++) {
          ans.push_back(arr[b]);
        }
        for (int j = c + 1; j <= a; j++) {
          ans.push_back(arr[a]);
        }
        return;
      }
    } else {
      for (int j = 1; j <= 5; j++) {
        int d = b + j;
        if (d + 1 > c) break;
        int diff = val - 2;
        if (diff > (c - d + 1) / 2 - 1) continue;
        if (diff < (c - d) / 5) continue;
        if (dp(idx - 1, j - 1)) {
          dfs(idx - 1, j - 1);
          for (int k = b + 1; k < d; k++) {
            ans.push_back(arr[b]);
          }
          int add = 0;
          for (int k = d; k <= c; k++) {
            ans.push_back(add + arr[b] + 1);
            add = (add + 1) % (arr[a] - arr[b] - 1);
          }
          for (int k = c + 1; k <= a; k++) {
            ans.push_back(arr[a]);
          }
          return;
        }
      }
    }
  }
}
int main() {
  scanf("%d", &N);
  arr.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
    if (arr[i]) fix.push_back(i);
  }
  if (fix.size() == 0) {
    printf("%d\n", N / 2);
    ans.resize(N);
    for (int i = 0; i < N - 1; i += 2) {
      ans[i] = i / 2 + 1;
      ans[i + 1] = i / 2 + 1;
    }
    if (N % 2) ans[N - 1] = ans[N - 2];
    for (int i = 0; i < N; i++) {
      printf("%d ", ans[i]);
    }
    return 0;
  }
  cache = vector<vector<int> >(fix.size(), vector<int>(5, -1));
  if (!dp(fix.size() - 1, 0)) {
    if (!dp(fix.size() - 1, 1))
      printf("-1");
    else if (fix.back() != N - 1) {
      int t = arr[fix.back()];
      printf("%d\n", (N - fix.back() - 2) / 2 + t);
      dfs(fix.size() - 1, 1);
      ans.push_back(arr[fix.back()]);
      int cnt = arr[fix.back()] + 1;
      for (int i = fix.back() + 2; i < N - 1; i += 2) {
        ans.push_back(cnt);
        ans.push_back(cnt);
        cnt++;
      }
      if (ans.size() != N) ans.push_back(cnt - 1);
      sort(ans.begin(), ans.end());
      for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
      }
    } else
      printf("-1");
  } else if (fix.back() != N - 2 &&
             (fix.back() == 0 || arr[fix.back() - 1] == 0 ||
              arr[fix.back() - 1] == arr[fix.back()])) {
    int t = arr[fix.back()];
    printf("%d\n", (N - fix.back() - 1) / 2 + t);
    dfs(fix.size() - 1, 0);
    int cnt = arr[fix.back()] + 1;
    for (int i = fix.back() + 1; i < N - 1; i += 2) {
      ans.push_back(cnt);
      ans.push_back(cnt);
      cnt++;
    }
    if (ans.size() != N) ans.push_back(cnt - 1);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
      printf("%d ", ans[i]);
    }
  } else {
    if (!dp(fix.size() - 1, 1))
      printf("-1");
    else if (fix.back() != N - 1) {
      int t = arr[fix.back()];
      printf("%d\n", (N - fix.back() - 2) / 2 + t);
      dfs(fix.size() - 1, 1);
      ans.push_back(arr[fix.back()]);
      int cnt = arr[fix.back()] + 1;
      for (int i = fix.back() + 2; i < N - 1; i += 2) {
        ans.push_back(cnt);
        ans.push_back(cnt);
        cnt++;
      }
      if (ans.size() != N) ans.push_back(cnt - 1);
      sort(ans.begin(), ans.end());
      for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
      }
    } else
      printf("-1");
  }
}
