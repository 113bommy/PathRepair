#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> indx;
  vector<pair<int, int> > insd;
  int n, k, a, g = 0, sum = 0;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    insd.push_back(make_pair(a, i + 1));
  }
  sort(insd.begin(), insd.end());
  while (sum <= k && g < n) {
    sum += insd[g].first;
    indx.push_back(insd[g].second);
    g++;
  }
  cout << g - 1 << endl;
  for (int h = 0; h < g - 1; ++h) {
    cout << indx[h] << " ";
  }
}
