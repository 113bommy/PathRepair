#include <bits/stdc++.h>
using namespace std;
int powermod(int base, int pw, int modulo) {
  int ans = 1;
  while (pw) {
    if (pw & 1) {
      ans = (1LL * base * ans) % modulo;
    }
    base = (1LL * base * base) % modulo;
    pw >>= 1;
  }
  return ans;
}
inline void debug(long double n) {
  cout << n << ' ';
  cout << "\n";
}
inline void debug(string s, long double n) {
  cout << s << ": ";
  cout << n << ' ';
  cout << "\n";
}
inline void debug(string s) {
  cout << s << " ";
  cout << "\n";
}
void print_array(int* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
void print_array(unsigned int* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
void print_array(long long int* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
void print_array(unsigned long long int* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
void print_array(float* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
void print_array(double* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
void print_array(long double* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(6);
  int n;
  double avg = 0;
  int ans = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    avg += a[i];
  }
  avg = avg / n;
  avg = 4.5 - avg;
  if (avg > 0) {
    sort(a, a + n);
    avg = avg * (double)n;
    int i = 0;
    while (avg > 0) {
      avg = avg - (5 - a[i]);
      i++;
      ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
