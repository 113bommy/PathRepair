#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  vector<int> val;
  float p = 0.00;
  cin >> n;
  int t = n;
  while (n--) {
    int a;
    cin >> a;
    val.push_back(a);
  }
  for (unsigned int i = 0; i < val.size(); i++) {
    p = p + (val.at(i) / 100.0);
  }
  cout << fixed << setprecision(8);
  cout << (p / t) * 100.0 << endl;
}
