#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  int cnt = 0, last = -1;
  for (register int i = (0); i < (int)(n); ++i) {
    int x;
    cin >> x;
    if (x < 0) {
      if (cnt < 2)
        cnt++;
      else {
        cnt = 1;
        v.push_back(i - last - 1);
        last = i - 1;
      }
    }
  }
  if (last != n - 1) v.push_back(n - 1 - last);
  cout << ((int)(v).size()) << endl;
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
    cout << *it << " ";
  cout << endl;
  return 0;
}
