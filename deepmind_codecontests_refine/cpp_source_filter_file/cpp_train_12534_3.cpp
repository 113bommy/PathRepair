#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;
long long arr[10];
int cnt[10];
void back_track(int id, int N, vector<int> &P) {
  if (id == N) {
    ans.push_back(P);
    return;
  }
  for (int i = -1; i < N; ++i) {
    if (i == id) continue;
    if (i != -1 && arr[i] % arr[id] != 0) continue;
    P[id] = i;
    back_track(id + 1, N, P);
  }
}
int main() {
  int N;
  cin >> N;
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    long long cp = arr[i];
    for (int j = 2; 1LL * j * j <= cp; ++j) {
      while (cp % j == 0) {
        cp /= j;
        cnt[i]++;
      }
    }
    if (cp != 1) cnt[i]++;
    if (cnt[i] == 1) cnt[i] = 0;
    sum += cnt[i];
  }
  vector<int> V(N);
  back_track(0, N, V);
  if (N == 1) {
    cout << cnt[N] + 1 << endl;
    return 0;
  } else {
    int mi = sum + N + 1;
    for (int i = 0; i < ans.size(); ++i) {
      vector<long long> tmp(N, 1);
      bool valid = 1;
      for (int j = 0; j < N && valid; ++j) {
        int p = ans[i][j];
        if (p != -1) {
          if (arr[j] > arr[p] / tmp[p] || arr[p] % (tmp[p] * arr[j]) != 0) {
            valid = 0;
            break;
          }
          tmp[p] *= arr[j];
        }
      }
      if (!valid) continue;
      int _cnt = 0, _sum = sum;
      for (int j = 0; j < N; ++j) {
        int p = ans[i][j];
        _cnt += p == -1;
        if (p != -1) _sum -= cnt[j] == 0 ? 1 : cnt[j];
      }
      mi = min(mi, _sum + (_cnt > 1) + N);
    }
    cout << mi << endl;
  }
}
