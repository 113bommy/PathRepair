#include <bits/stdc++.h>
using namespace std;
int cst[21][21];
int val(int pos, vector<int> &v) {
  int res = 0;
  for (int i = 0; i < v.size(); i++) {
    res += cst[v[i]][v[pos]] * abs(pos - i);
  }
  return res;
}
int main() {
  srand(643456);
  char s[112345];
  int n, m;
  cin >> n >> m;
  vector<int> p, v(m);
  scanf(" %s", s);
  for (int i = 0; i < n - 1; i++) {
    int a = s[i] - 'a';
    int b = s[i + 1] - 'a';
    cst[a][b] = cst[b][a] = cst[a][b] + 1;
  }
  for (int i = 0; i < m; i++) {
    v[i] = i;
  }
  int mn = 10000000000000000LL;
  for (int i = 0; i < 20000; i++) {
    random_shuffle(v.begin(), v.end());
    for (int j = 0; j < 20; j++) {
      for (int k = 0; k < m - 1; k++) {
        int cst1 = val(k, v) + val(k + 1, v);
        swap(v[k], v[k + 1]);
        int cst2 = val(k, v) + val(k + 1, v);
        if (cst1 < cst2) swap(v[k], v[k + 1]);
      }
    }
    int res = 0;
    for (int j = 0; j < m; j++) res += val(j, v);
    if (res < mn) {
      mn = res;
    }
  }
  cout << mn / 2 << endl;
}
