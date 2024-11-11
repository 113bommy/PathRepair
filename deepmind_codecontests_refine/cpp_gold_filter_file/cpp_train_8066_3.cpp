#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n;
  vector<pair<int, int> > possum;
  vector<pair<int, int> > negsum;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a > 0)
      possum.push_back(make_pair(a, b));
    else
      negsum.push_back(make_pair(-1 * a, b));
  }
  if (possum.size() > 0) {
    sort(possum.begin(), possum.end());
    for (int i = 1; i < possum.size(); i++)
      possum[i].second = possum[i - 1].second + possum[i].second;
  }
  if (negsum.size() > 0) {
    sort(negsum.begin(), negsum.end());
    for (int i = 1; i < negsum.size(); i++)
      negsum[i].second = negsum[i - 1].second + negsum[i].second;
  }
  if (possum.size() > negsum.size()) {
    if (negsum.size() != 0)
      cout << possum[negsum.size()].second + negsum[negsum.size() - 1].second
           << endl;
    else
      cout << possum[0].second << endl;
  } else if (possum.size() < negsum.size()) {
    if (possum.size() != 0)
      cout << possum[possum.size() - 1].second + negsum[possum.size()].second
           << endl;
    else
      cout << negsum[0].second << endl;
  } else
    cout << possum[possum.size() - 1].second + negsum[possum.size() - 1].second
         << endl;
  return 0;
}
