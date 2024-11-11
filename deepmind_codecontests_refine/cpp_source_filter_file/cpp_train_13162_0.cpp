#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  int b[100];
  bool f = false;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int sum = 0;
  int max = b[0];
  sum += b[0];
  for (int i = 0; i < n; i++) {
    sum += b[i];
    if (max < b[i]) max = b[i];
  }
  if ((sum - max) <= s)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
