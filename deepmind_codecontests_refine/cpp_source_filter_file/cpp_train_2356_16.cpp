#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, i, k;
  vector<long int> a;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k;
    a.push_back(k);
  }
  long int c = 0;
  for (auto i = a.begin(); i < a.end(); i++) {
    if (i != a.begin() && i != (a.end() - 1)) {
      if (*i > *(i - 1) && *i > *(i + 1)) {
        c++;
      }
      if (*i < *(i - 1) && *i < *(i - 1)) {
        c++;
      }
    }
  }
  cout << c << endl;
  return 0;
}
