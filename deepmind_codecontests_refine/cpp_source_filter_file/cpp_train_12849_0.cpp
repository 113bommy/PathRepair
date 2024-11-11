#include <bits/stdc++.h>
using namespace std;
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int i = 0; i < t.size(); i++) s << t[i] << " ";
  return s;
}
char s[1001];
int main() {
  int i, j, k, m, n, T;
  while (~scanf("%d%d", &n, &m)) {
    bool f = 1;
    int c[m + 1], first, second;
    memset(c, 0, sizeof(c));
    for (i = 0; i < n; i++) {
      scanf("%s", s);
      for (j = 0; j < m; j++)
        if (s[j] == 'G')
          first = j;
        else if (s[j] == 'S')
          second = j;
      if (first > second)
        f = 0;
      else if (first < second)
        c[first]++;
    }
    if (!f)
      puts("-1");
    else {
      for (i = 0, k = 0; i < m; i++)
        if (c[i]) k++;
      printf("%d\n", k);
    }
  }
}
