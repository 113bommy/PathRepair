#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[601] = {0}, temp, count = 0, i;
  cin >> n;
  while (n--) {
    cin >> temp;
    a[temp]++;
  }
  for (i = 1; i < 600; i++) {
    if (a[i] >= 1) {
      count++;
    }
  }
  cout << count;
  return 0;
}
