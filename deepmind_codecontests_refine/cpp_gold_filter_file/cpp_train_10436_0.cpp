#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int testcase;
  cin >> testcase;
  while (testcase--) {
    int n, m, ele;
    cin >> n;
    map<int, int> make_pair;
    for (int i = 0; i < n; i++) {
      cin >> ele;
      make_pair[ele]++;
    }
    unsigned long long total = 0;
    unsigned long long remain = 0;
    for (std::map<int, int>::iterator i = make_pair.begin();
         i != make_pair.end(); ++i) {
      total += (i->second + remain) / (i->first);
      remain = (i->second + remain) % (i->first);
    }
    cout << total << "\n";
  }
  return 0;
}
