#include <bits/stdc++.h>
using namespace std;
long long n, a, i, b, c, r;
set<int> P[200001];
int main() {
  for (cin >> n; i < 2 * n; i++) cin >> b, P[b - 1].insert(i);
  for (i = 0; i < n; i++)
    r += abs(c - *(P[i].begin())), c = *(P[i].begin()),
                                   P[i].erase(*(P[i].begin()));
  for (i = c = 0; i < n; i++)
    r += abs(c - *(P[i].begin())), c = *(P[i].begin());
  cout << r;
}
