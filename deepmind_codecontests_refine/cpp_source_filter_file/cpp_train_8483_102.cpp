#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, s;
  cin >> k >> s;
  int min, max;
  int razn, od = 0;
  if (k > s)
    min = s;
  else
    min = k;
  max = k + s - min - min;
  razn = min;
  while (max != 0 && max != 1) {
    max /= 2;
    od++;
  }
  cout << razn << " " << od;
}
