#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
using namespace std;
double EPS = 1e-7;
vector<pair<int, int> > a, b;
vector<int> res[3000];
int m[3000];
bool B[3000];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  long long s = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    s += x;
    if (y == 1)
      a.push_back(make_pair(x, i + 1));
    else
      b.push_back(make_pair(x, i + 1));
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for (int i = 0; i < min(k, (int)a.size()); i++) {
    res[i].push_back(a[i].second);
    B[i] = 1;
    m[i] = a[i].first;
  }
  for (int i = k; i < a.size(); i++) {
    b.push_back(a[i]);
  }
  sort(b.begin(), b.end());
  for (int i = a.size(); i < k; i++) {
    res[i].push_back(b[b.size() - 1].second);
    m[i] = b[b.size() - 1].first;
    b.erase(b.begin() + b.size() - 1);
  }
  for (int i = 0; i < b.size(); i++) {
    res[k - 1].push_back(b[i].second);
    m[k - 1] = min(m[k - 1], b[i].first);
  }
  double Res = s;
  for (int i = 0; i < k; i++) {
    if (B[i]) Res -= m[i] / 2.0;
  }
  printf("%.1f\n", Res);
  for (int i = 0; i < k; i++) {
    printf("%d ", res[i].size());
    for (int j = 0; j < res[i].size(); j++) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
}
