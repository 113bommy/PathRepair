#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  int total;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "++X" || s == "X++") {
      total++;
    } else {
      total--;
    }
  }
  cout << total;
}
