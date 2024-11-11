#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 123;
int neg = 0;
int pos = 0;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    if (p.first > 0)
      pos++;
    else
      neg++;
  }
  if (pos == 1 || neg == 1) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
  return 0;
}
