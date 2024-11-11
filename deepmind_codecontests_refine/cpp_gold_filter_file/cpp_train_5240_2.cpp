#include <bits/stdc++.h>
using namespace std;
int id[30][200001];
int cnt[30];
void precedure(string &s, int k) {
  string t = s;
  for (int i = 1; i < k; i++) s += t;
  for (int i = 0; i < s.size(); i++) {
    int t = s[i] - 'a';
    id[t][++cnt[t]] = i;
  }
}
int main() {
  int k, n;
  string s;
  cin >> k;
  cin >> s;
  cin >> n;
  precedure(s, k);
  while (n--) {
    int p;
    string c;
    cin >> p >> c;
    int j = c[0] - 'a';
    int t = id[j][p];
    s[t] = '*';
    for (int i = p; i < cnt[j]; i++) id[j][i] = id[j][i + 1];
  }
  for (int i = 0; i < s.size(); i++)
    if (s[i] != '*') cout << s[i];
  cout << endl;
  return 0;
}
