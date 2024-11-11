#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long prev[10001] = {0};
  long diff[10001] = {0};
  long arr[10001] = {0};
  int t = 0;
  for (int i = 1; i <= n; i++) {
    long a;
    cin >> a;
    arr[a] = 1;
    if (prev[a] == 0) {
      diff[a] = 0;
      t++;
    } else {
      if (diff[a] == -1)
        continue;
      else if (diff[a] == 0) {
        diff[a] = i - prev[a];
      } else {
        if (diff[a] != i - prev[a]) {
          diff[a] == -1;
          t--;
        }
      }
    }
    prev[a] = i;
  }
  cout << t;
  if (t != 0) {
    for (int i = 0; i < 10001; i++) {
      if (arr[i] == 1) {
        if (diff[i] != -1) {
          cout << "\n" << i << " " << diff[i];
        }
      }
    }
  }
}
