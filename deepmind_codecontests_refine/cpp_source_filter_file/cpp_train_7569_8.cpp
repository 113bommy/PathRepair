#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  vector<int> div;
  for (int i = 1; i * i <= n; i++) {
    if ((n % i) == 0) {
      div.push_back(i);
      if (i * i != n) div.push_back(n / i);
    }
  }
  sort(div.begin(), div.end());
  for (int i = 0; i < div.size(); i++) {
    reverse(s.begin(), s.begin() + div[i]);
    cout << s << endl;
  }
  return 0;
}
