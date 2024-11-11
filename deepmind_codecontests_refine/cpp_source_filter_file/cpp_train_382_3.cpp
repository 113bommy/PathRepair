#include <bits/stdc++.h>
using namespace std;
int p[110];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n / 2; i++) {
    scanf("%d", &p[i]);
  }
  sort(p, p + n);
  int j = 0;
  int r = 0, r1 = 0;
  for (int i = 1; i <= n; i += 2) {
    r += abs(p[j++] - i);
  }
  j = 0;
  for (int i = 2; i <= n; i += 2) {
    r1 += abs(p[j++] - i);
  }
  cout << min(r, r1) << endl;
  return 0;
}
