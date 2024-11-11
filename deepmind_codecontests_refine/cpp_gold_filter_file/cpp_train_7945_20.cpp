#include <bits/stdc++.h>
using namespace std;
int main() {
  multimap<long long int, long long int> m;
  long long int n;
  cin >> n;
  while (n--) {
    long long int x, y;
    cin >> x >> y;
    m.insert(make_pair(x, y));
  }
  multimap<long long int, long long int>::iterator it, it1;
  int c = 0;
  for (it = m.begin(); it != m.end(); it++) {
    bool p, q, r, s;
    p = false;
    q = false;
    r = false;
    s = false;
    for (it1 = m.begin(); it1 != m.end(); it1++) {
      if (it->first == it1->first && it->second > it1->second) p = true;
      if (it->first == it1->first && it->second < it1->second) q = true;
      if (it->first > it1->first && it->second == it1->second) r = true;
      if (it->first < it1->first && it->second == it1->second) s = true;
    }
    if (p & q & r & s) c++;
  }
  cout << c;
}
