#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int n;
  cin >> n;
  long long s = 0, k = (long long)n * (n - 1) / 2;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m, s += m;
  }
  for (int i = 0; i < n; i++)
    cout << i + (s - k) / n + (i < (s - k) % n) << " ";
}
