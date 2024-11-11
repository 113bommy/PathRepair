#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int n, m;
int a[maxn];
int main() {
  scanf("%d", &n);
  cout << ((n + 2) / 3) / 12 << " " << ((n + 2) / 3) % 12 << endl;
  return 0;
}
