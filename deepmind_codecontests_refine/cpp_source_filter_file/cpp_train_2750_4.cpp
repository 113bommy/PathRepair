#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1001] = {0};
  int N, t, max = 0, num = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> t;
    a[t]++;
  }
  for (int i = 0; i < 1000; i++)
    if (a[i] > max) max = a[i];
  for (int i = 0; i < 1000; i++)
    if (a[i] != 0) num++;
  cout << max << ' ' << num << endl;
}
