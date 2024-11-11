#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x[100000], count = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < t - 1; i++) {
    if (x[i] != x[i + 1]) count++;
  }
  cout << count << endl;
  return 0;
}
