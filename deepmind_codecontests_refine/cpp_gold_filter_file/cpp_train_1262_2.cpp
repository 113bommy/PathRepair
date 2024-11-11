#include <bits/stdc++.h>
using namespace std;
vector<long long> ans;
int n1;
void solve(int a) {
  long long rez = 0;
  int poz = 1;
  while (1) {
    int poz1 = n1 - (n1 - poz) % a;
    rez += 1LL * (poz + poz1) * ((poz1 - 1) / a + 1) / 2;
    poz1 += a;
    poz1 -= n1;
    if (poz1 == 1) {
      ans.push_back(rez);
      break;
    }
    poz = poz1;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  ans.push_back(1LL * (n + 1) * n / 2);
  ans.push_back(1);
  n1 = n;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) {
      solve(i);
      solve(n / i);
    }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    if (i > 0 && ans[i] == ans[i - 1]) continue;
    printf("%I64d ", ans[i]);
  }
  return 0;
}
