#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  map<string, string> tmp;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string a, b;
    cin >> a >> b;
    tmp[a + " " + b] = 1;
  }
  cout << tmp.size();
}
