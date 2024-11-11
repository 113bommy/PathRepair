#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, count = 0;
  string b;
  cin >> a;
  for (size_t i = 0; i < a; i++) {
    cin >> b;
    if (b.at(0) == '+' || b.at(2) == '+') {
      count++;
    } else if (b.at(0) == '-' || b.at(2) == '-') {
      count--;
    }
  }
  cout << count;
  return 0;
}
