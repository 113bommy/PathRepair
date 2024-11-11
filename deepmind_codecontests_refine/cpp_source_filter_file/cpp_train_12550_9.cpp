#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  cin >> n >> c;
  int sivan[n + 10];
  int i;
  for (i = 0; i < n; i++) {
    cin >> sivan[i];
  }
  int gonona = 1, maximum = 1;
  for (i = 0; i < n - 1; i++) {
    if (sivan[i + 1] - sivan[i] <= c) {
      gonona++;
      if (maximum < gonona) maximum = gonona;
    } else {
      gonona = 1;
      if (gonona > maximum) maximum = gonona;
    }
  }
  cout << maximum;
  return 0;
}
