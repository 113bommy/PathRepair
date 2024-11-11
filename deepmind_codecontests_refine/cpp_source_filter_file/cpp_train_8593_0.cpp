#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  map<int, int> ms;
  while (t--) {
    char ch;
    cin >> ch;
    int a;
    cin >> a;
    int p = 0, i = 1;
    while (a) {
      p += i * (a % 2);
      a /= 10;
      i *= 3;
    }
    if (ch == '+')
      ms[p]++;
    else if (ch == '-')
      ms[p]--;
    else
      cout << ms[p] << endl;
  }
}
