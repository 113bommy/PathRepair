#include <bits/stdc++.h>
using namespace std;
bool e[1 << 18];
int n, x;
int main() {
  scanf("%d %d", &n, &x);
  vector<int> v;
  e[0] = e[x] = 1;
  v.push_back(x);
  for (int i = 1; i < (1 << n); ++i) {
    if (e[i ^ x]) continue;
    e[i] = 1;
    v.push_back(i);
  }
  printf("%d\n", v.size() - 1);
  for (int i = 1; i < v.size(); ++i) printf("%d ", v[i] ^ v[i - 1]);
  return 0;
}
