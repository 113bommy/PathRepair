#include <bits/stdc++.h>
using namespace std;
int main() {
  int st, nd, cnt = 0, n, female[5500] = {0}, male[5500] = {0};
  char gen;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> gen;
    cin >> st >> nd;
    for (int j = st; j <= nd; j++) {
      if (gen == 'M')
        male[j]++;
      else
        female[j]++;
    }
  }
  for (int i = 0; i < 370; i++) {
    if (cnt < min(male[i], female[i]))
      cnt = min(male[i], female[i]);
    else
      continue;
  }
  cout << cnt * 2;
  return 0;
}
