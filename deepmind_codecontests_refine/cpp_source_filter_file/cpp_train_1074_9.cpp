#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  int coef = 0;
  for (int i = 0; i < n; i += 2) {
    if (i != n - 1)
      coef += (v.at(i) * v.at(i)) - (v.at(i + 1) * v.at(i + 1));
    else
      coef += v.at(i) * v.at(i);
  }
  cout << coef * 3.1415926;
}
