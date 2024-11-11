#include <bits/stdc++.h>
using namespace std;
int n, x, i, w[100005], sum;
int main() {
  cin >> n >> x;
  for (i = 1; i <= n; i++) {
    cin >> w[i];
    sum = sum + w[i];
  }
  if (x - sum - n >= 0)
    cout << "YES";
  else
    cout << "NO";
}
