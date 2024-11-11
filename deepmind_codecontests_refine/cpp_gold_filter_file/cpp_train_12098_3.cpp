#include <bits/stdc++.h>
using namespace std;
int n;
void result() {
  set<int> s;
  s.insert(0);
  int i = 1;
  while (i * i <= n) {
    int d = n / i;
    s.insert(d);
    s.insert(n / d);
    i++;
  }
  cout << s.size() << "\n";
  for (auto v : s) {
    cout << v << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    result();
  }
  return 0;
}
