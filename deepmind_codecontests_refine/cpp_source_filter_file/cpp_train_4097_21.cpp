#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  deque<char> d;
  while (cin >> c) {
    while (!d.empty() && d.back() > c) d.pop_back();
    d.push_back(c);
  }
  while (!d.empty()) {
    cout << d.front();
    d.pop_front();
  }
  return 0;
}
