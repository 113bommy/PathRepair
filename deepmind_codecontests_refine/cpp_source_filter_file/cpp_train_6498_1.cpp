#include <bits/stdc++.h>
using namespace std;
int main() {
  long long sum = 0;
  int prev;
  string s, p = "bear";
  cin >> s;
  for (int i = 0; i < ((int)((s).size())); ++i) {
    if (s.substr(i, 4) == p) {
      sum += (i - prev + 1) * (1 + ((int)((s).size())) - (i + 4));
      prev = i + 1;
    }
  }
  cout << sum;
}
