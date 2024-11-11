#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n >> d;
  char o;
  map<int, int> s;
  map<int, int> b;
  map<int, int>::iterator its;
  map<int, int>::iterator itb;
  for (int i = 0; i < n; i++) {
    cin >> o;
    int p, d;
    cin >> p >> d;
    if (o == 'S') {
      s[p] += d;
    }
    if (o == 'B') {
      b[p] += d;
    }
  }
  if (!s.empty()) {
    its = s.begin();
    if (d < s.size())
      for (int i = 0; i < d - 1; i++) {
        its++;
      }
    else {
      its = s.end();
      its--;
    }
  }
  if (!b.empty()) {
    itb = b.end();
    itb--;
  }
  if (!s.empty())
    for (int i = 0; i < d && i < s.size(); i++) {
      cout << 'S' << ' ' << its->first << ' ' << its->second << endl;
      its--;
    }
  if (!b.empty())
    for (int i = 0; i < d && i < b.size(); i++) {
      cout << 'B' << ' ' << itb->first << ' ' << itb->second << endl;
      itb--;
    }
  return 0;
}
