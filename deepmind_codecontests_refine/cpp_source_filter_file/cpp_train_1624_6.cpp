#include <bits/stdc++.h>
using namespace std;
const int MAX_LEN = 1000001;
char s[MAX_LEN], b[11];
int scmp(char *s, char *sbs) {
  while (*sbs) {
    if (*s != *sbs) return 0;
    sbs++;
    s++;
  }
  return 1;
}
int main() {
  int n, l, l2;
  scanf("%s%d", s, &n);
  l = strlen(s);
  vector<pair<int, int> > p;
  for (int i = 0; i < n; i++) {
    scanf("%s", b);
    l2 = strlen(b);
    for (int j = 0; j < l - l2 + 1; j++)
      if (scmp(s + j, b)) p.push_back(make_pair(j, l2));
  }
  sort(p.begin(), p.end());
  int k = p.size();
  int t = 0, maxl = 0, maxpos = 0;
  for (int j = 0; j < l; j++) {
    while (t < k && p[t].first < j) t++;
    if (t < k) {
      int r = p[t].first + p[t].second;
      for (int i = t; i < k && p[i].first < r; i++)
        r = min(r, p[t].first + p[t].second);
      int tl = r - j - 1;
      if (tl > maxl) {
        maxl = tl;
        maxpos = j;
      }
    } else {
      int tl = l - j;
      if (tl > maxl) {
        maxl = tl;
        maxpos = j;
      }
      break;
    }
  }
  cout << maxl << " " << maxpos;
  return 0;
}
