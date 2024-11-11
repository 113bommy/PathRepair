#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
int ft['z' - 'a' + 1][200001];
vector<int> letter['z' - 'a' + 1];
int query(int i, int x) {
  return x > 0 ? ft[i][x] + query(i, x - (x & -x)) : 0;
}
void update(int i, int x, int v) {
  while (x <= (int)letter[i].size()) ft[i][x] += v, x += (x & -x);
}
int index(int i, int before) {
  before--;
  int lo = 0, hi = letter[i].size();
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    query(i, mid) > before ? hi = mid : lo = mid;
  }
  return hi;
}
int main() {
  if (fopen("data.in", "r")) freopen("data.in", "r", stdin);
  int k, n;
  string t;
  cin >> k;
  cin >> t;
  string s = "", change = "";
  for (int i = 0; i < k; i++) s += t;
  for (int i = 0; i < (int)s.size(); i++) letter[s[i] - 'a'].push_back(i);
  for (int i = 0; i < 'z' - 'a'; i++)
    for (int j = 0; j < (int)letter[i].size(); j++) update(i, j + 1, 1);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int occ, pos;
    char ch;
    cin >> occ;
    cin >> ch;
    pos = index(ch - 'a', occ);
    s[letter[ch - 'a'][pos - 1]] = ' ';
    update(ch - 'a', pos, -1);
  }
  for (int i = 0; i < (int)s.size(); i++)
    if (s[i] != ' ') cout << s[i];
  cout << endl;
  return 0;
}
