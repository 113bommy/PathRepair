#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& cout, const vector<T>& a) {
  if ((int)a.size() == 0) {
    return (cout << "()");
  }
  cout << "(" << a[0];
  for (int i = 1; i < (int)a.size(); i++) {
    cout << "; " << a[i];
  }
  return (cout << ")");
}
template <typename T>
ostream& operator<<(ostream& cout, const set<T>& a) {
  if ((int)a.size() == 0) {
    return (cout << "{}");
  }
  auto it = a.begin();
  cout << "{" << *it;
  ++it;
  for (; it != a.end(); ++it) {
    cout << "; " << *it;
  }
  return (cout << "}");
}
template <typename T>
ostream& operator<<(ostream& cout, const multiset<T>& a) {
  if ((int)a.size() == 0) {
    return (cout << "{}");
  }
  auto it = a.begin();
  cout << "{" << *it;
  ++it;
  for (; it != a.end(); ++it) {
    cout << "; " << *it;
  }
  return (cout << "}");
}
template <typename T1, typename T2>
ostream& operator<<(ostream& cout, const pair<T1, T2>& a) {
  return cout << "(" << a.first << "; " << a.second << ")";
}
const int nmax = 2000 * 1000;
const int inf = 2000 * 1000 * 1000;
const long long infl = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
const int mod = 1000 * 1000 * 1000 + 7;
const long double pi = acos(-1.0);
int n;
long double ma[nmax], mi[nmax], ans1[nmax], ans2[nmax];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ma[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> mi[i];
  }
  long double x1 = 0, x2 = 0;
  for (int i = n - 1; i >= 0; i--) {
    long double c = ma[i];
    long double d = mi[i];
    long double b = (x1 - x2 + c + d);
    long double cc = -(c + d) * x2 + d;
    long double D = b * b - 4 * cc;
    if (D < 1e-8) {
      D = 0;
    }
    ans2[i] = (b + sqrtl(D)) / 2;
    ans1[i] = c + d - ans2[i];
    x1 += ans1[i];
    x2 += ans2[i];
  }
  for (int i = 0; i < n; i++) {
    printf("%.10lf ", (double)ans1[i]);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%.10lf ", (double)ans2[i]);
  }
}
