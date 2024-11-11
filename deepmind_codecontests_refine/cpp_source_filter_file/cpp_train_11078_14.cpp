#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> s;
  s.insert(0);
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    set<int> temp;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
      if (s.find(*it + a[i]) == s.end()) temp.insert(*it + a[i]);
    }
    for (set<int>::iterator it = temp.begin(); it != temp.end(); it++) {
      s.insert(*it);
    }
  }
  int prev = 0;
  int c = 0;
  vector<int> v;
  s.insert(INT_MAX);
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
    v.push_back(*it);
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > prev + d) {
      break;
    }
    while (v[i] <= prev + d) i++;
    i--;
    prev = v[i];
    c++;
  }
  cout << prev << " " << c << endl;
}
