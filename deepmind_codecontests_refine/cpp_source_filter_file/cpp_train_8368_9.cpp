#include <bits/stdc++.h>
using namespace std;
template <typename T>
string tostr(T a) {
  stringstream ss;
  ss << a;
  return ss.str();
}
template <typename C>
void PRINTALL(const C& arr, string delim = " ") {
  for (typename C::const_iterator it = arr.begin(); it != arr.end(); it++)
    cout << *(it) << " ";
  cout << endl;
}
long long int mod = 1000000007;
long long int modpow(int k) {
  if (!k) return 1;
  long long int a = 2;
  for (int i = 1; i < k; i++) {
    a = (a * 2) % mod;
  }
  return a;
}
int main() {
  int n;
  string s;
  cin >> s;
  n = s.length();
  int count = 0;
  long long int sum = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1') {
      sum += modpow(2 * n - i - 2) % mod;
      count++;
    }
  }
  cout << sum << endl;
  return 0;
}
