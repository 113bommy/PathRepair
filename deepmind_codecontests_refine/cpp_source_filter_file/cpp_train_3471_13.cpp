#include <bits/stdc++.h>
using namespace std;
struct sq {
  long long n;
  long long money;
  bool occ;
  sq() { occ = 0; }
};
bool cmp(sq a, sq b) { return a.money > b.money; }
int main() {
  sq tsq;
  long long n, k, b, temp, mon = 0;
  vector<sq> inp, srt;
  cin >> n >> k >> b;
  for (long long i = 0; i < n; i++) {
    cin >> temp;
    tsq.n = i;
    tsq.money = temp;
    inp.push_back(tsq);
  }
  srt = inp;
  srt.pop_back();
  sort(srt.begin(), srt.end(), cmp);
  cout << endl;
  long long ii;
  for (ii = 0; ii < k && ii < n - 1; ii++) {
    mon += srt[ii].money;
    inp.at(srt[ii].n).occ = 1;
  }
  if (mon < b) {
    cout << n << endl;
    return 0;
  }
  mon -= srt[ii - 1].money;
  for (long long i = 0; i < n; i++) {
    if ((inp.at(i).occ) || (inp.at(i).money + mon > b) || (i == n - 1)) {
      cout << i + 1 << endl;
      break;
    }
  }
  return 0;
}
