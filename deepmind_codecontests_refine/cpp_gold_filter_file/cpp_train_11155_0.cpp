#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  vector<long long int> v;
  for (long long int i = 0; i < n; i++) {
    long long int a;
    scanf("%lld", &a);
    v.push_back(a);
  }
  long long int ans = 0;
  for (long long int i = 1; i < n; i++) {
    if ((v[i] == 3 && v[i - 1] == 2) || (v[i] == 2 && v[i - 1] == 3)) {
      cout << "Infinite" << endl;
      return 0;
    }
    if (v[i] == 1 && v[i - 1] == 2)
      ans += 3;
    else if (v[i] == 1 && v[i - 1] == 3)
      ans += 4;
    if (v[i] == 2) ans += 3;
    if (v[i] == 3) ans += 4;
    if (v[i] == 2 && v[i - 1] == 1 && v[i - 2] == 3 && i >= 1) ans--;
  }
  cout << "Finite" << endl;
  cout << ans << endl;
}
