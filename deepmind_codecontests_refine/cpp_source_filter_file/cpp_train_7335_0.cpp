#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n = 0;
  cin >> n;
  vector<int> x;
  vector<int> y;
  int a = 0;
  int suma = 0, sumb = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a > 0) {
      suma += a;
      x.push_back(a);
    } else {
      sumb += abs(a);
      y.push_back(abs(a));
    }
  }
  if (suma > sumb) {
    cout << "first\n";
    return 0;
  } else if (sumb > suma) {
    cout << "second\n";
    return 0;
  }
  if (x.size() == 0) {
    cout << "second" << endl;
    return 0;
  }
  if (y.size() == 0) {
    cout << "first" << endl;
    return 0;
  }
  int i = 0;
  while (x[i] == y[i] && i < min((int)x.size(), (int)y.size())) {
    i++;
  }
  if (i == min((int)x.size(), (int)y.size())) {
    if (x.size() == y.size()) {
      if (a > 0)
        cout << "first\n";
      else
        cout << "second\n";
    } else if (x.size() > y.size()) {
      cout << "first\n";
    } else
      cout << "second\n";
  } else {
    if (x[i] > y[i]) {
      cout << "first\n";
    } else
      cout << "second\n";
  }
  return 0;
}
