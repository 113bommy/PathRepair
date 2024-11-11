#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  bool a[3005] = {false};
  for (long long int i = 1; i <= n; i++) {
    long long int g;
    cin >> g;
    a[g] = true;
  }
  for (long long int i = 1; i < 3005; i++) {
    if (a[i] == false) {
      cout << i;
      break;
    }
  }
}
