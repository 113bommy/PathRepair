#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  vector<int> odd, even;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x % 2 == 0)
      even.push_back(x);
    else
      odd.push_back(x);
  }
  if (odd.size() < even.size())
    cout << odd.size();
  else {
    cout << even.size() + (odd.size() - even.size()) / 3;
  }
}
