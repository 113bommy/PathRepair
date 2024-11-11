#include <bits/stdc++.h>
using namespace std;
bool pri[100500] = {1, 1, 0};
long long ppp[100500] = {1};
int k = 1;
void pp() {
  for (int i = 2; i < 100500; ++i)
    if (!pri[i]) {
      ppp[k++] = i;
      for (int j = 2 * i; j < 100500; j += i) pri[j] = 1;
    }
}
long long sb(long long a, long long b) {
  if (a != 0) return sb(b % a, a);
  return b;
}
int main() {
  int tt;
  cin >> tt;
  pp();
  while (tt--) {
    long long a, m;
    cin >> a >> m;
    long long d = sb(a, m);
    m /= d;
    long long b = m, t = m;
    for (int i = 1; ppp[i] != 0 && ppp[i - 1] * ppp[i - 1] <= a; ++i) {
      if (b % ppp[i] == 0) {
        t = t / ppp[i] * (ppp[i] - 1);
        while (b % ppp[i] == 0) b /= ppp[i];
      }
    }
    if (b != 1)
      cout << t / b * (b - 1) << endl;
    else
      cout << t << endl;
  }
}
