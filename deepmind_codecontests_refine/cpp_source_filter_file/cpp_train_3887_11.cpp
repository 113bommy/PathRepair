#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  int *data = new int[n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int s = 0;
    cin >> s;
    data[i] = s;
    sum = sum + s;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (data[i] < data[j]) {
        int s = data[i];
        data[i] = data[j];
        data[j] = s;
      }
    }
  }
  int ss = 0;
  for (int i = 0; i < n; i++) {
    ss = ss + data[i];
    if (ss > (sum - ss)) {
      cout << i + 1;
      return 0;
    }
  }
  return 0;
}
