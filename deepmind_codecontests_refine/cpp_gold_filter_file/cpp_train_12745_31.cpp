#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, now, num;
  cin >> p >> now >> num;
  if (now - num > 1) cout << "<< ";
  for (int i = 0; i < num; i++) {
    if (now - num + i >= 1) cout << now - num + i << " ";
  }
  cout << "(" << now << ") ";
  for (int i = 0; i < num; i++) {
    if (now + i < p) cout << now + i + 1 << " ";
  }
  if (now + num < p) cout << ">>";
  return 0;
}
