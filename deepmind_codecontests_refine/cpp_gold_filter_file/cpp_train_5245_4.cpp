#include <bits/stdc++.h>
using namespace std;
static const int INF = 1000000005;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int r, c;
vector<vector<int> > buf;
set<pair<int, int> > colS[100005], rowS;
int nottop[100005];
int ans[100005];
int main() {
  cin >> r >> c;
  buf.resize(c, vector<int>(r));
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) {
      int a;
      scanf("%d", &a);
      buf[j][i] = a;
    }
  swap(r, c);
  for (int i = 0; i < c; ++i) {
    int smallest = INF;
    for (int j = 0; j < r; ++j)
      if (buf[j][i] != -1) {
        smallest = min(smallest, buf[j][i]);
        colS[i].insert(make_pair(buf[j][i], j));
      }
    for (int j = 0; j < r; ++j)
      if (buf[j][i] != -1 && buf[j][i] != smallest) {
        nottop[j]++;
      }
  }
  for (int i = 0; i < r; ++i) rowS.insert(make_pair(nottop[i], i));
  int fail = 0;
  for (int i = 0; i < r; ++i) {
    pair<int, int> tmp = *rowS.begin();
    if (tmp.first != 0) {
      fail = 1;
      break;
    }
    rowS.erase(rowS.begin());
    ans[i] = tmp.second;
    int ii = tmp.second;
    for (int j = 0; j < c; ++j)
      if (buf[ii][j] != -1) {
        colS[j].erase(make_pair(buf[ii][j], ii));
        if (!colS[j].empty()) {
          int nxt = colS[j].begin()->first;
          if (nxt != buf[ii][j]) {
            set<pair<int, int> >::iterator it = colS[j].begin();
            while (it != colS[j].end()) {
              if (it->first != nxt) break;
              rowS.erase(make_pair(nottop[it->second], it->second));
              --nottop[it->second];
              rowS.insert(make_pair(nottop[it->second], it->second));
              ++it;
            }
          }
        }
      }
  }
  if (fail) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < r; ++i) printf("%d\n", ans[i] + 1);
  return 0;
}
