#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
int n;
int x[maxn], y[maxn];
vector<pair<int, int> > ans, ans2, ansMiddle;
int main(int argc, char *argv[]) {
  cin >> n;
  for (int i = (1); i <= (n); i++) scanf("%d", x + i);
  int p = 1;
  for (int i = (29); i >= (0); i--) {
    for (int j = (p); j <= (n); j++)
      if (x[j] & (1 << i)) {
        if (j == p) break;
        swap(x[p], x[j]);
        ans.push_back(make_pair(j, p));
        ans.push_back(make_pair(p, j));
        ans.push_back(make_pair(j, p));
        break;
      }
    if (x[p] & (1 << i)) {
      for (int j = (1); j <= (n); j++)
        if (p != j && (x[j] & (1 << i))) {
          x[j] ^= x[p];
          ans.push_back(make_pair(j, p));
        }
      p++;
      if (p == n + 1) break;
    }
  }
  int sumBase = p - 1;
  for (int k = (1); k <= (n); k++) scanf("%d", y + k);
  p = 1;
  for (int i = (29); i >= (0); i--) {
    for (int j = (p); j <= (n); j++)
      if (y[j] & (1 << i)) {
        if (j == p) break;
        swap(y[p], y[j]);
        ans2.push_back(make_pair(j, p));
        ans2.push_back(make_pair(p, j));
        ans2.push_back(make_pair(j, p));
        break;
      }
    if (y[p] & (1 << i)) {
      for (int j = (1); j <= (n); j++)
        if (p != j && (y[j] & (1 << i))) {
          y[j] ^= y[p];
          ans2.push_back(make_pair(j, p));
        }
      p++;
      if (p == n + 1) break;
    }
  }
  reverse(ans2.begin(), ans2.end());
  int wei[33];
  for (int i = (1); i <= (sumBase); i++) {
    int j = 29;
    while (!((1 << j) & x[i])) j--;
    wei[i] = j;
  }
  for (int i = (1); i <= (n); i++) {
    if (y[i] == 0) {
      ansMiddle.push_back(make_pair(i, i));
      continue;
    }
    vector<int> a;
    while (y[i] != 0) {
      int j = 29;
      while (!((1 << j) & y[i])) j--;
      bool find = false;
      for (int k = (1); k <= (sumBase); k++)
        if (wei[k] == j) {
          find = true;
          y[i] ^= x[k];
          a.push_back(k);
          break;
        }
      if (!find) {
        printf("-1\n");
        exit(0);
      }
    }
    if (a[0] != i) {
      ansMiddle.push_back(make_pair(i, i));
      ansMiddle.push_back(make_pair(i, a[0]));
    }
    for (int k = 1; k < ((int)(a).size()); k++)
      ansMiddle.push_back(make_pair(i, a[k]));
  }
  cout << ((int)(ans).size()) + ((int)(ans2).size()) + ((int)(ansMiddle).size())
       << "\n";
  for (typeof((ans).begin()) it = (ans).begin(); it != (ans).end(); it++)
    printf("%d %d\n", it->first, it->second);
  for (typeof((ansMiddle).begin()) it = (ansMiddle).begin();
       it != (ansMiddle).end(); it++)
    printf("%d %d\n", it->first, it->second);
  for (typeof((ans2).begin()) it = (ans2).begin(); it != (ans2).end(); it++)
    printf("%d %d\n", it->first, it->second);
  return 0;
}
