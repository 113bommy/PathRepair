#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int counter = 0;
  int i = 0, j;
  for (i = 10, j = 1; i <= 1000000000; i *= 10, j++)
    if (n > i) counter += pow(2, j);
  string s = "";
  while (n > 0) {
    if (n % 10 == 4)
      s += "0";
    else
      s += "1";
    n /= 10;
  }
  reverse(s.begin(), s.end());
  unsigned long decimal = bitset<10>(s).to_ulong();
  counter += decimal + 1;
  cout << counter << endl;
}
