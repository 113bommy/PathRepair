#include <bits/stdc++.h>
using namespace std;
struct Knight {
  int p;
  int c;
  int i;
  long long res;
};
int main() {
  multiset<long long> coins;
  int n, k;
  cin >> n >> k;
  vector<Knight> kn(n);
  int ndx = 0;
  for (auto& item : kn) {
    item.i = ndx++;
    cin >> item.p;
  }
  for (auto& item : kn) {
    cin >> item.c;
    item.res = item.c;
  }
  sort(kn.begin(), kn.end(),
       [&](Knight kn1, Knight kn2) { return kn1.p < kn2.p; });
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    kn[i].res += sum;
    if (k > 0) {
      if (coins.size() >= k) {
        if (*(coins.begin()) < kn[i].c) {
          sum += kn[i].c;
          sum -= *(coins.begin());
          coins.erase(coins.begin());
          coins.insert(kn[i].c);
        }
      } else {
        coins.insert(kn[i].c);
        sum += kn[i].c;
      }
    }
  }
  sort(kn.begin(), kn.end(),
       [&](Knight kn1, Knight kn2) { return kn1.i < kn2.i; });
  for (auto& item : kn) {
    cout << item.res << ' ';
  }
  cout << endl;
  return 0;
}
