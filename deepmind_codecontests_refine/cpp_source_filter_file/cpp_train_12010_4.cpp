#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> v;
  for (int i = 0; i < n; i++) {
    int r;
    cin >> r;
    v.insert(r);
  }
  set<int>::iterator it = v.begin();
  if (v.size() == 1)
    cout << "1" << endl;
  else
    cout << *(++it) << endl;
  return 0;
}
