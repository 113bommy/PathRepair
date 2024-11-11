#include <bits/stdc++.h>
using namespace std;
int main() {
  long int a, n;
  cin >> a;
  vector<int> num;
  for (int i = 0; i < a; i++) {
    cin >> n;
    num.push_back(n);
  }
  for (int i = 0; i < num.size() - 1; i++) {
    cout << num.at(i) + num.at(i + 1);
  }
  cout << num.back();
  return 0;
}
