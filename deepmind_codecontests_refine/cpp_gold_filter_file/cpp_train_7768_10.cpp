#include <bits/stdc++.h>
using namespace std;
int n, x, i, w[100005], sum;
int main() {
  cin >> n >> x;
  for (i = 1; i <= n; i++) {
    cin >> w[i];
    sum = sum + w[i];
  }
  if (sum + n - 1 == x)
    cout << "YES";
  else
    cout << "NO";
}
