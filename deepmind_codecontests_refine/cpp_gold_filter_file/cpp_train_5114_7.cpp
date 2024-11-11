#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ara[n + 3];
  for (int i = 0; i < n; i++) {
    cin >> ara[i];
  }
  int sum = 0;
  for (int j = 1; j < n; j++) {
    if (ara[j - 1] == 1 && ara[j + 1] == 1 && ara[j] == 0) {
      sum++;
      j = j + 2;
    }
  }
  cout << sum << endl;
}
