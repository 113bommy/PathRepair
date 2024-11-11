#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
bool used[1000000 + 1];
int main() {
  int n, x, need = 0;
  vector<int> v;
  scanf("%d", &n);
  for (int(i) = 0; (i) < (n); ++(i)) {
    scanf("%d", &x);
    used[x] = true;
  }
  for (int(i) = (1); (i) <= (1000000 / 2); ++(i))
    if (used[i] && used[1000000 - i + 1])
      need++;
    else if (used[i] && !used[1000000 - i + 1])
      v.push_back(1000000 - i + 1);
    else if (!used[i] && used[1000000 - i + 1])
      v.push_back(i);
  for (int(i) = (1); (i) <= (1000000 / 2); ++(i))
    if (need && !used[i] && !used[1000000 - i + 1])
      v.push_back(i), v.push_back(1000000 - i + 1);
  printf("%d\n", int((v).size()));
  for (int(i) = 0; (i) < int((v).size()); ++(i)) printf("%d ", v[i]);
  return 0;
}
