#include <bits/stdc++.h>
using namespace std;
bool used[100001];
int d[100001], pos[100001], n, data[100001];
set<pair<int, int> > res;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &data[i]);
    if (pos[data[i]] == 0)
      pos[data[i]] = i;
    else if (d[data[i]] == 0) {
      d[data[i]] = i - pos[data[i]];
      pos[data[i]] = i;
    } else if (i - pos[data[i]] != d[data[i]])
      used[data[i]] = true;
    else
      pos[data[i]] = i;
  }
  for (int i = 1; i <= n; i++)
    if (!used[i]) res.insert(make_pair(data[i], d[data[i]]));
  printf("%d\n", res.size());
  for (set<pair<int, int> >::iterator it = res.begin(); it != res.end(); it++)
    printf("%d %d\n", it->first, it->second);
}
