#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  vector<int> v;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) v.push_back(i + 1);
  int leader = 0;
  for (int i = 0; i < k; i++) {
    int a;
    scanf("%d", &a);
    leader = (leader + a) % (n - i);
    printf("%d ", v[leader]);
    v.erase(v.begin() + 1);
  }
  return 0;
}
