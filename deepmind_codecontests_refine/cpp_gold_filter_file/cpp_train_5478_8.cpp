#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  map<int, int> a;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;
    a[temp]++;
  }
  if (a.size() != 2) {
    cout << "NO";
    return 0;
  } else {
    map<int, int>::iterator p = a.begin();
    int c = p->second, x = p->first;
    p++;
    if (c != p->second) {
      cout << "NO";
      return 0;
    }
    cout << "YES\n" << x << " " << p->first;
  }
  return 0;
}
