#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[4], b[4];
  string first, second;
  int answer;
  cin >> a[0] >> a[1] >> a[3] >> a[2];
  cin >> b[0] >> b[1] >> b[3] >> b[2];
  for (int i = 0; i < 4; i++) {
    if (a[i] != 'X') first += a[i];
    if (b[i] != 'X') second += b[i];
  }
  first += first;
  answer = first.find(second);
  if (answer != -1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
