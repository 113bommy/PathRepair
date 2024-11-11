#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007ll;
const long long Mod = 1000000009ll;
const long long inf = (long long)5e18;
const double eps = 1e-12;
const long long N = 1000005;
const long long LOGN = 19;
const double PI = 3.14159265358979323846;
template <class T>
T max2(T a, T b) {
  return a < b ? b : a;
}
template <class T>
T min2(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T max3(T a, T b, T c) {
  return Max2(Max2(a, b), c);
}
template <class T>
T min3(T a, T b, T c) {
  return Min2(Min2(a, b), c);
}
template <class T>
T max4(T a, T b, T c, T d) {
  return Max2(Max2(a, b), Max2(c, d));
}
template <class T>
T min4(T a, T b, T c, T d) {
  return Min2(Min2(a, b), Max2(c, d));
}
void print(int a[], int s, int e) {
  for (int i = s; i <= e; i++) cout << a[i] << " ";
  cout << "\n";
}
void print(vector<int> &v, int s, int e) {
  for (int i = s; i <= e; i++) cout << v[i] << " ";
  cout << "\n";
}
void print(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << "\n";
}
long long mul(long long a, long long b, long long m = Mod) {
  return (long long)(a * b) % m;
}
long long add(long long a, long long b, long long m = Mod) {
  a += b;
  if (a >= m) a -= m;
  if (a < 0) a += m;
  return a;
}
long long power(long long a, long long b, long long m = Mod) {
  if (b == 0) return 1;
  if (b == 1) return (a % m);
  long long x = power(a, b / 2, m);
  x = mul(x, x, m);
  if (b % 2) x = mul(x, a, m);
  return x;
}
int main() {
  long long n;
  scanf("%lld", &n);
  ;
  long long a[n];
  bool fOdd = false;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    ;
    if (a[i] % 2 == 1)
      fOdd = !fOdd;
    else {
      if (fOdd) {
        if (a[i] == 0) {
          cout << "NO";
          printf("\n");
          ;
          return 0;
        }
      }
    }
  }
  if (fOdd)
    cout << "NO*";
  else
    cout << "YES";
  printf("\n");
  ;
  return 0;
}
