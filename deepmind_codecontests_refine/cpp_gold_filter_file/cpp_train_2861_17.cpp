#include <bits/stdc++.h>
using namespace std;
int ans[1000033];
int main() {
  int n, M, T;
  scanf("%d%d%d", &n, &M, &T);
  list<long long> l;
  bool ok = false;
  int kol = 0, last = 0;
  for (int i = 0; i < n; i++) {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    int t = h * 60 * 60 + m * 60 + s;
    if (kol > 0) {
      while (l.front() <= t) {
        kol--;
        l.pop_front();
        if (kol == 0) break;
      }
    }
    if (kol < M) {
      last++;
      kol++;
      l.push_back(t + T);
    } else
      l.back() = t + T;
    ans[i] = last;
    if (kol == M) ok = true;
  }
  if (!ok) {
    cout << "No solution" << endl;
    return 0;
  }
  cout << last << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}
