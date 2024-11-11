#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  long long f = 0;
  long long m = 0;
  long long s = 0;
  long long ed = 0;
  long long el = 0;
  long long em = 0;
  long long ek = 0;
  for (long long i = 0; i < a.size(); ++i) {
    char q;
    q = a[i];
    if (q == 'F') {
      long long w = i - f + ed;
      if (ed == i) {
        w = 0;
      } else if (!f)
        w = i;
      else if (ek == i - 1)
        w = em + 1;
      else if (i - f > em)
        w = i - f;
      else if (i - f > em - (i - f))
        w = em + 1;
      else
        w = em;
      if (w > s) s = w;
      ++ed;
      ek = i;
      el = i - f;
      em = w;
      ++f;
    } else {
      ed = 0;
      ++m;
    }
  }
  cout << s << '\n';
}
