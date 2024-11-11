#include <bits/stdc++.h>
int DBG = 0;
using namespace std;
const int MAXN = 1E6 + 5;
int n;
bool is_prime[MAXN], mark[MAXN];
vector<pair<int, int> > res;
int main() {
  scanf("%d", &n);
  for (int i = 4; i <= n; i += 2) is_prime[i] = 1;
  for (int i = 3; i * 2 <= n; ++i)
    if (!is_prime[i]) {
      vector<int> tmp;
      for (int j = 3 * i; j <= n; j += i)
        if (!mark[j]) tmp.push_back(j), is_prime[j] = 1;
      if (tmp.size() & 1 == 0 && !mark[2 * i]) tmp.push_back(2 * i);
      tmp.push_back(i);
      for (int j = 0; j < int(tmp.size()) - 1; j += 2) {
        res.push_back(pair<int, int>(tmp[j], tmp[j + 1]));
        mark[tmp[j]] = 1;
        mark[tmp[j + 1]] = 1;
      }
    }
  int prev = 2;
  for (int j = 4; j <= n; j += 2)
    if (!mark[j]) {
      if (prev != -1)
        res.push_back(pair<int, int>(prev, j)), prev = -1;
      else
        prev = j;
    }
  printf("%d\n", int(res.size()));
  for (int i = 0; i < int(res.size()); ++i)
    printf("%d %d\n", res[i].first, res[i].second);
}
