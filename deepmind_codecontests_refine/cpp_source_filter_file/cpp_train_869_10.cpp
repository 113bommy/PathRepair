#include <bits/stdc++.h>
using namespace std;
int n, m, p, k, a;
vector<int> s;
double posi;
int main() {
  cin >> n >> m;
  s.resize(m + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a >> posi;
    for (int j = m; j >= 0; j--) {
      if (j == a) {
        s[j] = *min_element(s.begin() + 1, s.begin() + j);
      } else {
        s[j] = s[j] + 1;
      }
    }
  }
  cout << *min_element(s.begin() + 1, s.end()) << endl;
  return 0;
}
