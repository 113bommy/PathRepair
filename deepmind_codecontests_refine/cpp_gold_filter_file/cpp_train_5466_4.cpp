#include <bits/stdc++.h>
using namespace std;
vector<set<string> > a(21);
set<string>::iterator ii, jj;
long long s = 0;
int main() {
  long long n;
  cin >> n;
  long long i;
  for (i = 0; i < n; i++) {
    string w;
    cin >> w;
    s += (w.size());
    a[w.size()].insert(w);
  }
  char t;
  cin >> t;
  long long total = (2 * s) / n;
  set<string> ans;
  for (i = 1; i <= 20; i++) {
    long long Next = total - i;
    while (a[i].size() > 0) {
      ii = a[i].begin();
      string one = (*ii);
      a[i].erase(one);
      ii = a[Next].begin();
      string two = (*ii);
      a[Next].erase(two);
      string f = one + t + two;
      string ff = two + t + one;
      if (f < ff)
        ans.insert(f);
      else
        ans.insert(ff);
    }
  }
  for (ii = ans.begin(); ii != ans.end(); ii++) cout << (*ii) << endl;
  return 0;
}
