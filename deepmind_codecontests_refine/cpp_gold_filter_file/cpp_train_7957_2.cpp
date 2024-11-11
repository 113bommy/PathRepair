#include <bits/stdc++.h>
using namespace std;
int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};
int Set(int n, int pos) { return n = (n | (1 << pos)); }
bool check(int n, int pos) { return (bool)(n & (1 << pos)); }
int clearr(int n, int pos) { return n = (n & ~(1 << pos)); }
int update(int n, int pos) { return n = (n ^ (1 << pos)); }
struct st {
  int idx, value;
} s[100];
bool cmp(st a, st b) {
  if (a.value > b.value)
    return true;
  else
    return false;
}
int main() {
  string str;
  int n, m;
  while (cin >> str) {
    int ara[30];
    cin >> n;
    for (int i = 0; i < 26; i++) {
      cin >> s[i].value;
      ara[i] = s[i].value;
      s[i].idx = i;
    }
    sort(s, s + 26, cmp);
    string ss = "";
    map<char, int> mp;
    map<int, char> mmp;
    int j = 0;
    for (char i = 'a'; i <= 'z'; i++, j++) {
      mmp[i] = j;
      mp[j] = i;
    }
    int t = 1;
    int i = 0;
    while (t <= n) {
      ss += mp[s[0].idx];
      t++;
    }
    str = str + ss;
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
      sum += (ara[mmp[str[i]]] * (i + 1));
    }
    cout << sum << endl;
  }
  return 0;
}
