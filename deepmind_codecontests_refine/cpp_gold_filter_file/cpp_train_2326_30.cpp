#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, n;
  vector<int> dayN;
  cin >> d;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    dayN.push_back(a);
  }
  int result = 0;
  for (int i = 0; i < n - 1; i++) {
    result += (d - dayN[i]);
  }
  cout << result;
}
