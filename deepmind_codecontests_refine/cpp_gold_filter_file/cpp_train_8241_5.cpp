#include <bits/stdc++.h>
using namespace std;
int freq[200005];
int main() {
  long long n, T, m, x, a, b, c;
  long long v[200005];
  vector<int> v1, v2;
  set<int> st;
  stack<char> stk;
  map<int, vector<int>> mp;
  string s;
  cin >> T;
  while (T--) {
    long long sum = 0;
    cin >> n >> m;
    x = m % 10;
    if (x == 0) {
      cout << "0" << endl;
    } else if (x == 5) {
      long long div = n / m;
      cout << 5 * (long long)ceil(1.0 * div / 2) << endl;
    } else if (x & 1) {
      sum = 0;
      long long div = n / m;
      long long div10 = div / 10;
      for (long long i = 1; i <= div % 10; i++) {
        sum += (x * i) % 10;
      }
      cout << sum + div10 * 45 << endl;
    } else {
      sum = 0;
      long long div = n / m;
      long long div5 = div / 5;
      for (long long i = 1; i <= div % 5; i++) {
        sum += (x * i) % 10;
      }
      cout << sum + div5 * 20 << endl;
    }
  }
  return 0;
}
