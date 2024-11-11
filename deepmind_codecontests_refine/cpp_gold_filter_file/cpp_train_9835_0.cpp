#include <bits/stdc++.h>
using namespace std;
int l[100020], r[100020];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  int pointer = 1, i = 0, counter = 0;
  while (pointer <= l[n - 1]) {
    if (pointer + m > l[i]) {
      counter = counter + r[i] - pointer + 1;
      pointer = r[i] + 1;
      i++;
    } else {
      pointer += m;
    }
  }
  cout << counter;
}
