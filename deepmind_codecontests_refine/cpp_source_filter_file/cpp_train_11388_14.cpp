#include <bits/stdc++.h>
using namespace std;
int n, a[1005];
bool cmp(int x, int y) { return x > y; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  sort(a + 1, a + 1005 + 1, cmp);
  if (a[1] <= (n + 1) / 2 || n == 1)
    cout << "YES";
  else
    cout << "NO";
}
