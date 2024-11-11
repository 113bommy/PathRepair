#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0, ap = 0;
  int counter = 0;
  int totalSteps;
  int sections = 0;
  cin >> n;
  vector<int> s;
  for (int i = 0; i < n; i++) {
    ap = a;
    cin >> a;
    if (a > ap)
      counter++;
    else {
      s.push_back(ap);
      counter = 0;
    }
    if (i == n - 1 && ap != 0) {
      s.push_back(a);
    }
  }
  totalSteps = accumulate(s.begin(), s.end(), 0);
  sections = s.size();
  cout << sections << endl;
  for (auto iter = s.begin(); iter < s.end(); iter++) {
    cout << *iter << " ";
  }
  cout << endl;
  return 0;
}
