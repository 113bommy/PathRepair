#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    set<int> s;
    int d;
    cin >> d;
    for (int i = 0; i < d; i++) {
      int a;
      cin >> a;
      s.insert(a);
    }
    cout << s.size() << endl;
  }
}
