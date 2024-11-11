#include <bits/stdc++.h>
using namespace std;
const long long M = 1e5 + 100;
long long n, k, a[M], o;
string t;
void no() {
  cout << "No";
  exit(0);
}
void yes() {
  cout << "Yes";
  exit(0);
}
inline long long pro(string s) {
  reverse(s.begin(), s.end());
  long long d = 0, ct = 1;
  long long sz = s.length() - 1;
  if (s[sz] == '-') sz--;
  for (long long i = (0); i <= (sz); i++) d += ct * (s[i] - '0'), ct *= 10;
  if (s[s.length() - 1] == '-') d *= -1;
  return d;
}
void bakh() {
  for (long long i = (0); i <= (n); i++)
    if (a[i] == -100000) return;
  long long d = 0;
  for (long long i = (0); i <= (n); i++) {
    d += a[i];
    if (d % k) no();
    d /= k;
  }
  if (d != 0) no();
  yes();
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (long long i = (0); i <= (n); i++) {
    cin >> t;
    if (t == "?")
      a[i] = -100000;
    else
      a[i] = pro(t);
    if (a[i] != -100000) {
      o++;
    }
  }
  if (k == 0) {
    if (a[0] == 0) yes();
    if (a[0] == -100000 && (o % 2)) yes();
    no();
  }
  bakh();
  if (n % 2 == 0) no();
  yes();
  return 0;
}
