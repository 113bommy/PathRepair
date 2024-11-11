#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    set<int> a;
    for (int i = 2; i * i <= n; ++i) {
      a.insert(i * i);
    }
    for (int i = 2; i * i * i <= n; ++i) {
      a.insert(i * i * i);
    }
    cout << a.size() << endl;
  }
  return 0;
}
