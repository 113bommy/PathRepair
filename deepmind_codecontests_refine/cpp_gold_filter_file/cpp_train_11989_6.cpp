#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string list[n];
  for (int i = 0; i < n; i++) {
    cin >> list[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (list[j][0] > list[j + 1][0]) {
        swap(list[j], list[j + 1]);
      }
    }
  }
  char temp = list[0][0];
  int sum = 0;
  int k = 1;
  for (int i = 1; i < n; i++) {
    if (temp == list[i][0]) {
      k++;
    }
    if (temp != list[i][0]) {
      int t = k / 2;
      int tp = (k + 1) / 2;
      sum = sum + t * (t - 1) / 2 + tp * (tp - 1) / 2;
      temp = list[i][0];
      k = 1;
    }
  }
  if (k >= 3) {
    int t = k / 2;
    int tp = (k + 1) / 2;
    sum = sum + t * (t - 1) / 2 + tp * (tp - 1) / 2;
  }
  cout << sum;
}
