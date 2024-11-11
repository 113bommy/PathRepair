#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6 + 6;
bool vis[mxN], have[mxN], already[mxN];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    have[x] = true;
  }
  int answer = 0, cnt = 0;
  int l = 1, r = 1;
  while (r <= 1e6) {
    cnt += have[r];
    if (r - l + 1 == m) {
      int ptr = r;
      while (cnt >= k) {
        if (have[ptr]) {
          --cnt;
          vis[ptr] = true;
          ++answer;
        }
        --ptr;
      }
      if (!vis[l] && have[l]) --cnt;
      ++l;
    }
    ++r;
  }
  cout << answer;
}
