#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, x, y;
    cin >> n >> x >> y;
    long long int maxi = x + y - 2 + 1;
    maxi = max(maxi, n);
    long long int mini = x + y - n;
    if (mini <= 0)
      mini = 1;
    else
      mini++;
    mini = min(mini, n);
    cout << mini << " " << maxi << endl;
  }
}
