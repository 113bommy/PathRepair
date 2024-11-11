#include <bits/stdc++.h>
using namespace std;
bool numCheck(int n) {
  set<int> meh;
  while (n) {
    meh.insert(n % 10);
    n /= 10;
  }
  return (meh.size() == 4);
}
int main() {
  int n;
  cin >> n;
  for (int i = n + 1; i <= 1e5; i++)
    if (numCheck(i)) return cout << i, 0;
}
