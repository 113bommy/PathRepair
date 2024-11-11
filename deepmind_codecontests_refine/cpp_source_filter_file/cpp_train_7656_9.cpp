#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int n;
  cin >> n;
  set<long long int> s;
  for (int i = 0; i < n; i++) {
    long long int p;
    cin >> p;
    s.insert(p);
  }
  if (s.size() <= 2) {
    cout << "YES\n";
  } else if (s.size() == 3) {
    long long int p1, q1, r1;
    p1 = *s.begin();
    s.erase(p1);
    q1 = *s.begin();
    s.erase(q1);
    r1 = *s.begin();
    if ((p1 + r1) >> 1 == q1)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else {
    cout << "NO\n";
  }
}
