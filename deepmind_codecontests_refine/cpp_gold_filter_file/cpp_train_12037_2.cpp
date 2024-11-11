#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  int a[x];
  long long int count = 0;
  for (int i = 0; i < x; ++i) {
    cin >> a[i];
  }
  sort(a, a + x);
  int min = a[0];
  if (y < min) {
    count = y;
  } else if (y == min) {
    count = y + 1;
  } else if (y > min) {
    int i = 0;
    while (a[i] < y) i++;
    if (a[i] == y)
      count = y - i + 1;
    else
      count = y - i;
  }
  cout << count << endl;
  return 0;
}
