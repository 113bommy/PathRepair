#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5;
int n, a[mxN], k;
void solve() {
  long long n;
  cin >> n;
  long long counto = 0, counte = 0;
  vector<long long> arre, arro;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    if (a % 2 == 0) {
      arre.push_back(a);
      counte += 1;
    } else {
      arro.push_back(a);
      counto += 1;
    }
  }
  sort(arre.begin(), arre.end());
  sort(arro.begin(), arro.end());
  long long diff = abs(counto - counte);
  if (counte == counto || diff == 1) {
    cout << 0 << endl;
    return;
  }
  diff -= 1;
  if (counte > counto) {
    cout << accumulate(arre.begin(), arre.begin() + diff, 0);
    return;
  } else if (counte < counto) {
    cout << accumulate(arro.begin(), arro.end() + diff, 0);
    return;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
