#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ar[n], sum = 0;
  for (int i = 0; i < n; i++) cin >> ar[i], sum += ar[i];
  sort(ar, ar + n);
  double avg = sum / (double)n;
  int i = 0;
  while (i < n && !(avg >= 4.5)) {
    sum -= ar[i];
    sum += 5;
    avg = sum / (double)n;
    i++;
  }
  cout << i << '\n';
  return 0;
}
