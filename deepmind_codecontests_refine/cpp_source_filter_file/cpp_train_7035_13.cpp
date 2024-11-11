#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int H[(int)(2e5 + 10)], i, j, k, n, m, a[(int)(2e5 + 10)];
int dp2[(int)(2e5 + 10)], dp[(int)(2e5 + 10)], bas, son;
string str, str2;
bool f(int x) {
  memset(H, 0, sizeof H);
  for (int i = 0; i <= x; i++) {
    H[a[i]] = 1;
  }
  int s = 0;
  for (int i = 0; s < str2.size() and i < str.size(); i++) {
    if (!H[i] and str[i] == str2[s]) s++;
  }
  return (str2.size() == s);
}
int main() {
  cin >> str;
  cin >> str2;
  bas = 0;
  son = str.size() - 1;
  for (i = 0; i < str.size(); i++) {
    cin >> a[i];
    a[i]--;
  }
  while (bas + 1 < son) {
    if (f((bas + son) / 2))
      bas = (bas + son) / 2;
    else
      son = (bas + son) / 2 - 1;
  }
  if (f(son)) bas = son;
  cout << bas + 1 << '\n';
}
