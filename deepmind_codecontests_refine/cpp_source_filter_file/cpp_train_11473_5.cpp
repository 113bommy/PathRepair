#include <bits/stdc++.h>
using namespace std;
void gcd(int a, int b) {
  vector<int> am;
  int i;
  for (i = 2; i <= a / 2; i++) {
    if (a % i == 0) {
      am.push_back(i);
    }
  }
  vector<int> bm;
  for (i = 2; i <= b / 2; i++) {
    if (b % i == 0) {
      bm.push_back(i);
    }
  }
  int max;
  if (am.size() >= bm.size()) {
    max = am.size();
  } else {
    max = bm.size();
  }
  if (max == 0) max = 1;
  vector<int> cm(max);
  vector<int>::iterator it, ls;
  if (am.size() != 0 && bm.size() != 0) {
    ls = set_intersection(am.begin(), am.end(), bm.begin(), bm.end(),
                          cm.begin());
  }
  if (*cm.begin() == 0) {
    cout << "Finite\n";
  } else {
    cout << "Infinite\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    gcd(a, b);
  }
}
