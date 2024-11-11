#include <bits/stdc++.h>
using namespace std;
int x[4], res;
int main() {
  int n, sum;
  cin >> n;
  int fp = 0;
  for (int i = 0; i < 4; i++) {
    cin >> x[i];
    fp += x[i];
  }
  for (int i = 1; i < n; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      cin >> x[j];
      sum += x[j];
    }
    if (sum > fp) res++;
  }
  cout << res;
}
