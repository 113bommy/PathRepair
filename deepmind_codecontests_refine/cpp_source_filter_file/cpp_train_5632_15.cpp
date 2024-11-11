#include <bits/stdc++.h>
using namespace std;
int main() {
  short arr[101]{0};
  short n, m;
  cin >> n >> m;
  for (size_t i = 0; i < m; i++) {
    int var;
    cin >> var;
    arr[var]++;
  }
  int numOfGroubs[101]{0};
  for (size_t i = 1; i <= 100; i++) {
    int sum = 0;
    for (size_t j = 1; j < 100; j++) {
      sum += arr[j] / i;
    }
    numOfGroubs[i] = sum;
  }
  for (int i = 100; i >= 1; i--) {
    if (numOfGroubs[i] >= n) {
      cout << i;
      return 0;
    }
  }
  cout << 0;
}
