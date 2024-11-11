#include <bits/stdc++.h>
using namespace std;
int main() {
  int bq[100001] = {0};
  int sq[100001] = {0};
  vector<int> buys;
  vector<int> sells;
  int n;
  size_t s;
  cin >> n >> s;
  while (n--) {
    char c;
    int p, q;
    cin >> c >> p >> q;
    if (c == 'B') {
      buys.push_back(p);
      bq[p] += q;
    } else {
      sells.push_back(p);
      sq[p] += q;
    }
  }
  sort(begin(sells), end(sells));
  sells.erase(unique(begin(sells), end(sells)), end(sells));
  int ssz = min(sells.size(), s);
  for (int i = ssz - 1; i >= 0; --i) {
    int p = sells[i];
    cout << "S " << p << " " << sq[p] << endl;
  }
  sort(begin(buys), end(buys));
  buys.erase(unique(begin(buys), end(buys)), end(buys));
  int bsz = min(buys.size(), s);
  for (auto rit = buys.rbegin(); rit != buys.rbegin() + bsz; ++rit) {
    int p = *rit;
    cout << "B " << p << " " << bq[p] << endl;
  }
}
