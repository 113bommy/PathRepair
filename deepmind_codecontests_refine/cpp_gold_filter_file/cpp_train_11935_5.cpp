#include <bits/stdc++.h>
using namespace std;
long long INF = INT_MAX;
long long mod = 1e9 + 7;
long double PI = 3.141592653;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, t;
  cin >> n >> t;
  long long tt = 0;
  vector<pair<int, int> > a[n + 1];
  for (int i = 0; i < n; i++) {
    int k1, k2;
    cin >> k1 >> k2;
    a[k1].push_back(make_pair(k2, i + 1));
  }
  long long pts = 0;
  long long sf = 0;
  multiset<pair<int, int> > have;
  multiset<pair<int, int> >::iterator it;
  multiset<pair<int, int> > have_ans;
  for (int i = n; i >= 1; i--) {
    for (int k = 0; k < a[i].size(); k++) {
      pair<int, int> last = make_pair(0, 0);
      if (!have.empty()) {
        it = have.end();
        it--;
        last = *it;
      }
      if (tt + a[i][k].first <= t && have.size() < i) {
        have.insert(a[i][k]);
        tt += a[i][k].first;
        continue;
      }
      if (a[i][k].first < last.first && have.size() <= i) {
        tt -= last.first;
        have.erase(last);
        tt += a[i][k].first;
        have.insert(a[i][k]);
      }
    }
    if (have.size() == i) {
      cout << have.size() << "\n" << have.size() << "\n";
      it = have.begin();
      while (it != have.end()) {
        cout << (*it).second << " ";
        it++;
      }
      cout << "\n";
      return 0;
    }
  }
  cout << "0\n0\n";
}
