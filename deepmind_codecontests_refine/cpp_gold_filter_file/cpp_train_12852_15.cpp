#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  vector<int> x;
  for (int i = 0; i < a; i++) {
    int r;
    cin >> r;
    x.push_back(r);
  }
  sort(x.rbegin(), x.rend());
  int counter = 0;
  for (int i = 0; i < a; i += b) counter += (x[i] - 1) * 2;
  cout << counter << endl;
  return 0;
}
