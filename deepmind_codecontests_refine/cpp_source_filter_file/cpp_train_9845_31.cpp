#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int m = 0;
  char c;
  while (cin >> c) {
    m += (c == 'A');
  }
  cout << ((m > n / 2) ? "Anton" : (m = n - m) ? "Friendship" : "Danik");
}
