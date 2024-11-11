#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const int xx[4] = {1, -1, 0, 0};
const int yy[4] = {0, 0, 1, -1};
long long inline in() {
  long long x = 0, c;
  for (; (unsigned)((c = getchar()) - '0') >= 10;) {
    if (c == '-') return -in();
    if (!~c) throw ~0;
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while ((unsigned)((c = getchar()) - '0') < 10);
  return x;
}
string name[105];
const int score[15] = {0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
int main() {
  ios::sync_with_stdio(false);
  int t, n;
  cin >> t;
  map<string, int> m;
  vector<vector<int> > v(105, vector<int>(105, 0));
  int pos = 0;
  while (t--) {
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
      cin >> s;
      if (m.find(s) == m.end()) {
        name[pos] = s;
        m[s] = pos;
        pos++;
      }
      int &p = m[s];
      if (i <= 10) v[p][0] += score[i];
      v[p][i]++;
    }
  }
  pos = 0;
  for (int i = 1; i < ((int)(m).size()); i++) {
    if (v[pos] < v[i]) pos = i;
  }
  cout << name[pos] << endl;
  for (int i = 0; i < ((int)(m).size()); i++) {
    swap(v[i][0], v[i][1]);
  }
  pos = 0;
  for (int i = 0; i < ((int)(m).size()); i++) {
    if (v[pos] < v[i]) pos = i;
  }
  cout << name[pos] << endl;
  return 0;
}
