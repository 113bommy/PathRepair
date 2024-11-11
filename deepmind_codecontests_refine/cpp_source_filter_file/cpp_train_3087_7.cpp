#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<char> v = {'a', 'e', 'i', 'o', 'u', 'y'};
  for (int i = 0; i < n - 1; i++) {
    if ((find(v.begin(), v.end(), s[i]) != v.end()) &&
        (find(v.begin(), v.end(), s[i + 1]) != v.end())) {
      s.erase(i, 1);
      i--;
    }
  }
  cout << s;
}
