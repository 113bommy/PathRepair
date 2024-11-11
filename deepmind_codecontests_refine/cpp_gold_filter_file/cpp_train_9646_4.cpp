#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
int st[11];
int n;
string s;
int mincnt = 0;
void search(int i) {
  if (i == n) {
    string t;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (st[j]) t += s[j], cnt++;
    }
    int j = 0;
    while (t[j] == '0') {
      j++;
      cnt--;
    }
    stringstream ss(t);
    int num;
    ss >> num;
    if ((int)sqrt(num) * (int)sqrt(num) == num) mincnt = max(cnt, mincnt);
    return;
  }
  st[i] = 0;
  search(i + 1);
  st[i] = 1;
  search(i + 1);
  st[i] = 0;
}
int main() {
  cin >> s;
  n = s.length();
  search(0);
  if (mincnt != 0)
    cout << n - mincnt;
  else
    cout << -1;
  return 0;
}
