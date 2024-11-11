#include <bits/stdc++.h>
using namespace std;
int main() {
  int m[10] = {0};
  int s = 0;
  int a;
  for (int i = 0; i < 6; i++) {
    cin >> a;
    m[a]++;
    s = max(s, m[a]);
  }
  if (s < 4) {
    cout << "Alien";
    return 0;
  }
  int e = 0, l = 0, b = 0;
  for (int i = 0; i < 10; i++) {
    if (m[i] >= 4) e++;
    if (m[i] == 1) l++;
  }
  if (l)
    cout << "Bear";
  else
    cout << "Elephant";
  return 0;
}
