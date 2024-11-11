#include <bits/stdc++.h>
const int MAXN = 5000;
const long long BOTTOM = -2123456789LL;
using namespace std;
vector<int> v;
int main() {
  int n, a, b;
  scanf("%d %d %d\n", &n, &a, &b);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  printf("%d\n", v[b] - v[b - 1]);
  fprintf(stderr, "Execution time = %.4lfsec",
          (double)clock() / (double)CLOCKS_PER_SEC);
  return 0;
}
