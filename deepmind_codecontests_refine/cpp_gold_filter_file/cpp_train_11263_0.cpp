#include <bits/stdc++.h>
using namespace std;
const long long int mxn = 1e5 + 1;
string s;
char cs[1000][1000];
int main() {
  long long int n, m, i, z, j, a = 0, r = 1, ans = 0, k = 0, cnt = 0, b = 0;
  long long int c = 1, x, sm, q, l = 1, y, d = 0, sum = 0, mx = 0, mn = 0;
  string ss, strn;
  char ch;
  cin >> n >> k >> s;
  vector<long long int> vct;
  vector<long long int>::iterator vit;
  set<long long int> st;
  set<long long int>::iterator sit;
  if (n == 1) {
    if (k)
      cout << 0;
    else
      cout << s;
    return 0;
  }
  if (s[0] != '1' && k) {
    s[0] = '1';
    k--;
  }
  long long int ara[1000];
  for (i = 1; i < n && k > 0; i++) {
    if (s[i] != '0') {
      s[i] = '0';
      k--;
    }
  }
  cout << s << endl;
  return 0;
}
