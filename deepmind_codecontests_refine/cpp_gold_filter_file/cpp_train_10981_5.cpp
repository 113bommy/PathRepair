#include <bits/stdc++.h>
using namespace std;
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long toint(string s) {
  long long a = 0, c = 1;
  ;
  for (int i = 0; i < s.size(); i++) {
    a += (s[s.size() - i - 1] - '0') * c;
    c *= 10;
  }
  return a;
}
string binary(int x) {
  string num = "";
  while (x != 0) {
    num += x % 2 + '0';
    x /= 2;
  }
  return num;
}
long long decimal(string x) {
  long long a = 1;
  long long u = 0;
  for (long long i = 0; i < x.size(); i++) {
    if (x[i] == '1') u += a;
    a *= 2;
  }
  return u;
}
void print(int n, int l) {
  if (n >> l & 1)
    cout << 1 << endl;
  else
    cout << 0 << endl;
}
long long brr[1000000];
int main() {
  long long n, l, r, x, c = 0;
  cin >> n >> l >> r >> x;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 1; i < (1 << n); i++) {
    int a = 0, mm = 10e9, mm1 = -1, y = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        a++;
        mm = min(mm, v[j]);
        mm1 = max(mm1, v[j]);
        y += v[j];
      }
    }
    if (a >= 2 && (mm1 - mm) >= x && y >= l && y <= r) c++;
  }
  cout << c << endl;
  return 0;
}
