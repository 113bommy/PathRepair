#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<int> v;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.insert(x);
    }
    int qtd = 0;
    while (!v.empty()) {
      int m = *v.begin();
      v.erase(m);
      if (m % 2 == 0) {
        qtd++;
        v.insert(m / 2);
      }
    }
    cout << qtd << endl;
  }
  return 0;
}
