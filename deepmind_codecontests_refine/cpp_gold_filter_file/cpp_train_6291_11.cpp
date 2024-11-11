#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k[n];
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  int min = 10000001;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    int tem;
    for (int j = 1; j <= k[i]; j++) {
      cin >> tem;
      sum += (tem * 5);
      sum += 15;
    }
    if (sum <= min) min = sum;
  }
  cout << min << endl;
  return 0;
}
