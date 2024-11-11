#include <bits/stdc++.h>
void swap(long long &a, long long &b) {
  long long t = 0;
  t = a;
  a = b;
  b = t;
}
using namespace std;
const int N = 2e5 + 5;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    k = k + i;
    cout << s[k + c] << "";
    c++;
    if ((k + c) >= n) {
      break;
    }
  }
  cout << endl;
}
