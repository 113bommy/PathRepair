#include <bits/stdc++.h>
using namespace std;
void print_ans(bool f) {
  if (f) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
long long int modular_pow(long long int base, long long int exponent,
                          long long int modulus) {
  long long int result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) result = (result * base) % modulus;
    exponent = exponent >> 1;
    base = (base * base) % modulus;
  }
  return result;
}
long long int ask(long long int l, long long int r) {
  long long int x;
  cout << "? " << l << " " << r << endl;
  cin >> x;
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k, x, y, l, r;
  cin >> n;
  vector<long long int> ans(n + 1, 0);
  long long int a12 = ask(1, 2);
  long long int a23 = ask(2, 3);
  long long int a13 = ask(1, 3);
  ans[1] = ((a12 - a23) + (a13)) / 2;
  ans[2] = a12 - ans[1];
  ans[3] = a13 - ans[1];
  for (int i = 4; i <= n; i++) {
    long long int x = ask(1, i);
    ans[i] = x - ans[1];
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
