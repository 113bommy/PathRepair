#include <bits/stdc++.h>
using namespace std;
map<string, int> ss;
int a[3000];
int s[3000];
string rs[3000];
int pos;
int finds(string str) {
  if (ss.find(str) == ss.end()) {
    pair<string, int> d;
    d.first = str;
    d.second = pos++;
    rs[pos - 1] = str;
    ss.insert(d);
  }
  return (*ss.find(str)).second;
}
int findf(int x) {
  if (a[x] == x)
    return x;
  else
    return findf(a[x]);
}
int main() {
  int n;
  ss.clear();
  memset(a, 0, sizeof(a));
  memset(s, 0, sizeof(s));
  pos = 0;
  cin >> n;
  for (int i = 0; i <= 2 * n; ++i) a[i] = i;
  while (n--) {
    string str1, str2;
    cin >> str1 >> str2;
    a[finds(str1)] = finds(str2);
    s[finds(str1)] += 1;
    s[finds(str2)] += 2;
  }
  int ans = 0;
  for (int i = 0; i < pos; ++i)
    if (s[i] == 1) {
      ans++;
    }
  cout << ans << endl;
  for (int i = 0; i < pos; ++i)
    if (s[i] == 1) {
      cout << rs[i] << " " << rs[findf(i)] << endl;
    }
  return 0;
}
