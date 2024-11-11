#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, co = 0;
  cin >> n;
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    int t, u;
    cin >> t >> u;
    a.push_back(t);
    b.push_back(u);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] == a[j] && i != j) {
        co++;
      }
    }
  }
  cout << co << flush;
}
