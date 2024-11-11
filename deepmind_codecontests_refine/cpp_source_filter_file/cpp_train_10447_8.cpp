#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int nextint() {
  int t;
  scanf("%d", &t);
  return t;
}
int nxt[26];
int n;
char arr[2000001];
char tmp[100];
map<int, int> res;
int query[10001];
pair<int, int> q[26];
int main() {
  scanf("%s", arr);
  n = strlen(arr);
  for (int i = 0; i < (n); i++) arr[i] -= 'a';
  for (int i = 0; i < (26); i++) nxt[i] = INF;
  int m = nextint();
  for (int i = 0; i < (m); i++) {
    int curset = 0;
    scanf("%s", tmp);
    for (int j = 0; tmp[j]; j++) curset |= (1 << (tmp[j] - 'a'));
    query[i] = curset;
    res[curset] = 0;
  }
  for (int i = (n - 1); i > (-1); i--) {
    nxt[arr[i]] = i;
    for (int j = 0; j < (26); j++) {
      q[j].first = nxt[j];
      q[j].second = j;
    }
    sort(q, q + 26);
    int curset = 0;
    for (int j = 0; j < (26); j++) {
      pair<int, int> &val = q[j];
      curset |= (1 << val.second);
      if (val.first == INF || (i != 0 && val.second == arr[j - 1])) break;
      if (res.find(curset) != res.end()) res[curset]++;
    }
  }
  for (int i = 0; i < (m); i++) printf("%d\n", res[query[i]]);
}
