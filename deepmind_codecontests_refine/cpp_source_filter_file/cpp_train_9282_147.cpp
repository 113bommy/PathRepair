#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  if (m > n && k > n)
    printf("No");
  else
    printf("Yes");
}
