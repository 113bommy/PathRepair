#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int A, B;
vector<int> a, b;
int main() {
  scanf("%d%d", &A, &B);
  int n = 0;
  while (n * (n + 1) / 2 <= A + B) n++;
  for (int i = n - 1; i > 0; i--) {
    if (A > i)
      A -= i, a.push_back(i);
    else
      b.push_back(i);
  }
  printf("%d\n", a.size());
  for (auto i : a) printf("%d ", i);
  printf("\n");
  printf("%d\n", b.size());
  for (auto i : b) printf("%d ", i);
  printf("\n");
  return 0;
}
