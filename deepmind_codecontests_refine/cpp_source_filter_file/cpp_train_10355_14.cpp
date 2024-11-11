#include <bits/stdc++.h>
using namespace std;
inline int ABS(int a) {
  if (a < 0) return (-a);
  return a;
}
inline int min(int a, int b, int c) { return min(a, min(b, c)); }
inline int max(int a, int b, int c) { return max(a, max(b, c)); }
inline int powmod(int x, int n, int _mod) {
  int res = 1;
  while (n) {
    if (n & 1) res = (res * x) % _mod;
    x = (x * x) % _mod;
    n >>= 1;
  }
  return res;
}
inline int gcd(int a, int b) {
  int t;
  while (b) {
    a = a % b;
    t = a;
    a = b;
    b = t;
  }
  return a;
}
inline int lcm(int a, int b) { return a / (gcd(a, b) * b); }
const int v5 = 100000;
const int v9 = 1000000000;
const int v6 = 1000000;
int n, m, k, c = 100000, Hy, Hm, Ay, Am, Dy, Dm, h, a, d;
vector<int> v;
inline void cinarr(int x[], int n) {
  for (int i = 0; i < (n); ++i) cin >> (x[i]);
}
inline void cinvec(vector<int> &arr, int n) {
  for (int i = 0; i < (n); ++i) {
    int x;
    cin >> (x);
    arr.push_back(x);
  };
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> Hy >> Ay >> Dy;
  cin >> Hm >> Am >> Dm;
  cin >> h >> a >> d;
  for (int i = (0); i < (1001); ++i)
    for (int j = (0); j < (151); ++j)
      for (int k = (0); k < (151); ++k)
        if (Ay + j > Dm) {
          if (Am <= Dy + k)
            c = min(c, (h * i) + (a * j) + (d * k));
          else {
            int l1 = Hm / (Ay + j - Dm);
            if (Hm % (Ay + j - Dm) != 0) l1++;
            int l2 = (Hy + i) / (Am - Dy - k);
            if ((Hy + i) % (Am - Dy - k) == 0) l2--;
            if (l2 >= l1) c = min(c, (h * i) + (a * j) + (d * k));
          }
        }
  cout << c << "\n";
  return 0;
}
