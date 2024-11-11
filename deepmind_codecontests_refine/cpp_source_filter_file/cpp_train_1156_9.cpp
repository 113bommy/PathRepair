#include <bits/stdc++.h>
using namespace std;
const int N = 10000007;
int prime[N + 10];
map<int, int> ma;
vector<pair<int, int> > vi;
vector<int> rx;
int ch(int d) {
  vector<pair<int, int> > tp = vi;
  int co = 0;
  for (int i = 0; i < (int)(tp.size()); ++i)
    if (tp[i].second > (1 << d)) return N;
  for (int i = 0; i < (int)(tp.size()); ++i)
    if (tp[i].second != (1 << d)) {
      ++co;
      break;
    }
  return co + d;
}
int main() {
  prime[0] = prime[1] = true;
  for (int i = 2; i * i <= N; ++i)
    if (prime[i] == 0)
      for (int j = i * i; j <= N; j += i)
        if (prime[j] == false) prime[j] = i;
  int n;
  scanf("%d", &n);
  if (n == 1) return puts("0"), 0;
  while (prime[n] != 0) {
    rx.push_back(prime[n]);
    n /= prime[n];
  }
  if (n > 1) rx.push_back(n);
  for (int i = 0; i < (int)(rx.size()); ++i) ma[rx[i]]++;
  map<int, int>::iterator it = ma.begin();
  for (; it != ma.end(); ++it) vi.push_back(make_pair(it->first, it->second));
  bool o = false;
  int co = 0;
  while (true) {
    o = true;
    for (int i = 0; i < (int)(vi.size()); ++i)
      if (vi[i].second != 1) {
        o = false;
        break;
      }
    if (o == true) {
      int ans = 1;
      for (int i = 0; i < (int)(vi.size()); ++i) ans *= vi[i].first;
      cout << ans << " " << co << endl;
      return 0;
    }
    int rr = N;
    for (int i = 1; i < (int)(25); ++i) rr = min(rr, ch(i));
    int ans = 1;
    for (int i = 0; i < (int)(vi.size()); ++i) ans *= vi[i].first;
    cout << ans << " " << rr << endl;
    return 0;
  }
}
