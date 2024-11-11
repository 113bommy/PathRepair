#include <bits/stdc++.h>
using namespace std;
int cnt;
int V[40000005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) V[i] = i;
  cnt = 1;
  for (int i = 2; i <= n; i++) {
    int tmp = V[cnt];
    for (int j = cnt; j < n + cnt; j += i) {
      int idx = min(j + i, n + cnt);
      swap(V[idx], tmp);
    }
    cnt++;
  }
  for (int i = cnt; i < cnt + n; i++) cout << V[i] << ' ';
}
