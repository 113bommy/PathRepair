#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, counter = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      float k = sqrt(j * j + i * i);
      if (k == (int)k && k <= n) counter++;
    }
  }
  cout << counter << endl;
}
