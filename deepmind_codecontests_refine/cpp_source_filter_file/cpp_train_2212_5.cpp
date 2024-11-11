#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v1, v2;
    long long int i, x, j, flag = 0;
    for (i = 0; i < n; i++) {
      cin >> x;
      if (x % 2 == 0)
        v1.push_back(x);
      else
        v2.push_back(x);
    }
    if ((v1.size()) % 2 == 0)
      cout << "YES\n";
    else {
      for (i = 0; i < v1.size(); i++) {
        for (j = 0; j < v1.size(); j++) {
          if (abs(v1[i] - v2[j]) == 1) {
            flag = 1;
            break;
          }
        }
      }
      if (flag == 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
