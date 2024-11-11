#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int n;
  cin >> n;
  string a;
  int b[n], c[n];
  for (int i = 0; i < n; i++) {
    cin >> a;
    cin >> b[i] >> c[i];
  }
  for (int i = 0; i < n; i++) {
    if (b[i] >= 2400 && c[i] > b[i]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
