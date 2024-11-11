#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long int mod = (1e9) + 7;
long long int po(long long int i, long long int j) {
  if (j == 0) return 1;
  long long int temp = po(i, j / 2);
  temp *= temp;
  temp %= mod;
  if (j % 2) {
    temp *= i;
    temp %= mod;
  }
  return temp;
}
int main() {
  long long int p, k;
  cin >> p >> k;
  if (k == 0) {
    cout << po(p - 1, p) << "\n";
    return 0;
  }
  if (k == 1) {
    cout << po(p, p) << "\n";
    return 0;
  }
  long long int tp = k;
  long long int m = 1;
  while (tp != 1) {
    tp *= k;
    tp %= p;
    m++;
  }
  long long int n = (p - 1) / m;
  cout << po(p, n) << "\n";
  return 0;
}
