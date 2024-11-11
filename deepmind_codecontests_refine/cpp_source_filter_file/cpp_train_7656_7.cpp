#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n, a[maxn];
int main() {
  scanf("%d", &n);
  vector<int> A;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    A.push_back(x);
  }
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  if (A.size() <= 2) printf("YES\n");
  if (A.size() == 3 && A[2] + A[0] == A[1] * 2)
    printf("YES\n");
  else
    printf("NO\n");
}
