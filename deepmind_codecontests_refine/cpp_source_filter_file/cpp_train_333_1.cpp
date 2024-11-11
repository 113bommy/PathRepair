#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  map<long long int, long long int> bag;
  for (long long int i = 0; i < n; i++) bag[v[i]]++;
  vector<pair<long long int, long long int> > vpll;
  vpll.push_back(pair<long long int, long long int>(0, 0));
  for (auto it = bag.begin(); it != bag.end(); ++it) {
    vpll.push_back(pair<long long int, long long int>(it->first, it->second));
  }
  vpll.push_back(pair<long long int, long long int>(1e18, 0));
  sort(vpll.begin(), vpll.end());
  vector<long long int> costL(vpll.size() + 2, 0), costR(vpll.size() + 2, 0);
  vector<long long int> countL(vpll.size() + 2, 0), countR(vpll.size() + 2, 0);
  for (int i = 1; i < vpll.size() - 1; i++) {
    int index = i;
    countL[index + 1] = countL[index] + vpll[index].second;
    costL[index] =
        costL[index - 1] +
        countL[index] * abs(vpll[index].first - vpll[index - 1].first);
  }
  for (int i = 1; i < vpll.size() - 1; i++) {
    int index = vpll.size() - i;
    countR[index - 1] = countR[index] + vpll[index].second;
    costR[index] =
        costR[index + 1] +
        countR[index] * abs(vpll[index].first - vpll[index + 1].first);
  }
  long long int ans = 1e18;
  for (int i = 1; i < vpll.size() - 1; i++) {
    long long int qtyA = countL[i];
    long long int qtyB = countR[i];
    long long int cA = costL[i - 1];
    long long int cB = costR[i + 1];
    long long int diffA = abs(vpll[i].first - vpll[i - 1].first);
    long long int diffB = abs(vpll[i].first - vpll[i + 1].first);
    for (int j = 0; j < 2; j++) {
      long long int tmp = 0;
      long long int req = max(0ll, k - vpll[i].second);
      long long int rmA = min(qtyA, req);
      long long int rmB = req - rmA;
      if (rmA) tmp += cA + rmA + (diffA - 1ll) * rmA;
      if (rmB) tmp += cB + rmB + (diffB - 1ll) * rmB;
      swap(qtyA, qtyB);
      swap(cA, cB);
      swap(diffA, diffB);
      ans = min(ans, tmp);
    }
  }
  cout << ans << endl;
}
