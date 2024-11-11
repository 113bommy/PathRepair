#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void print(long long* a, long long n) {
  long long i;
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
long long arrMax(long long* a, long long n) {
  long long i, max = a[0];
  for (i = 1; i < n; i++) {
    if (a[i] > max) max = a[i];
  }
  return max;
}
void print2d(long long a[][100], long long m, long long n) {
  long long i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      cout << setw(2) << a[i][j];
    }
    cout << endl;
  }
}
void fio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
set<long long> calculateFactor(long long n) {
  set<long long> temp;
  long long l = sqrt(n);
  for (long long i = 1; i <= l; i++) {
    if (n % i == 0) {
      temp.insert(i);
      temp.insert(n / i);
    }
  }
  return temp;
}
int32_t main() {
  fio();
  long long n;
  cin >> n;
  if (n == 1)
    cout << 4;
  else if (n > 36)
    cout << -1;
  else {
    while (n > 1) {
      cout << 8;
      n -= 2;
    }
    if (n & 1) {
      cout << 0;
      n--;
    }
  }
}
