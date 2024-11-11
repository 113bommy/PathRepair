#include <bits/stdc++.h>
using namespace std;
vector<int> G[2 * 100000 + 5];
string S;
int N;
bool tell(int x) {
  int cur = 0;
  int mn = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'R' and cur + 1 == x) {
      continue;
    }
    mn = min(mn, cur);
    cur += (S[i] == 'R' ? 1 : -1);
  }
  return (cur < mn);
}
bool Base(int x) {
  int cur = 0;
  int mn = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'R' and cur + 1 == x) {
      continue;
    }
    mn = max(mn, cur);
    cur += (S[i] == 'R' ? 1 : -1);
  }
  return (cur > mn);
}
int main() {
  cin >> S;
  N = S.size();
  if (S[N - 1] == 'R') {
    for (int i = 0; i < N; ++i) {
      S[i] = char('L' + 'R' - S[i]);
    }
  }
  if (Base(10000000)) {
    cout << 1;
    return 0;
  }
  if (tell(1) == 0) {
    cout << 0;
    return 0;
  }
  int L = 1;
  int R = 1000000;
  while (L != R) {
    int mid = ceil((L + R) / 2.0);
    if (tell(mid))
      L = mid;
    else
      R = mid - 1;
  }
  cout << L;
}
