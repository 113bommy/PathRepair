#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
T gcd(T a, T b) {
  return a ? gcd(b % a, a) : b;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T sgn(T a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
int n;
int m;
const int N = 1024;
vector<bitset<N>> v[N];
int a[N][N], st[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    stringstream ss(s);
    char ch;
    int x;
    while (ss >> x) {
      ss >> ch;
      bitset<N> res;
      for (int j = 0; j < x; j++) {
        int y;
        ss >> y >> ch;
        y--;
        res[y] = 1;
        a[i][y] = ((int)(v[i]).size());
      }
      v[i].push_back(res);
    }
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      bool ok = true;
      auto res = (v[i][a[i][j]] ^ v[j][a[j][i]]);
      for (int k = 0; k < n; k++) ok &= res[k];
      if (ok) {
        ans.push_back(make_pair(i, j));
        st[i]++;
        st[j]++;
      }
    }
  }
  bool ok = ((int)(ans).size()) == n - 1;
  for (int i = 0; i < n; i++) ok &= st[i] == ((int)(v[i]).size());
  if (!ok)
    printf("-1\n");
  else {
    printf("%d\n", ((int)(ans).size()));
    for (auto w : ans) printf("%d %d\n", w.first + 1, w.second + 1);
  }
  return 0;
}
