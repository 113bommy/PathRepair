#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int a[MAXN + 1], b[MAXN + 1], c[MAXN + 1];
bool cmp(int x, int y) { return a[x] > a[y]; }
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    c[i] = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  sort(c, c + n, cmp);
  vector<int> res;
  res.push_back(c[0]);
  for (int i = 1; i < n; i += 2) {
    if (b[c[i]] >= b[c[i + 1]])
      res.push_back(c[i]);
    else
      res.push_back(c[i + 1]);
  }
  if (n % 2 == 0) res.push_back(c[n - 1]);
  cout << (int)res.size() << "\n";
  for (auto x : res) printf("%d ", x + 1);
  printf("\n");
  return 0;
}
