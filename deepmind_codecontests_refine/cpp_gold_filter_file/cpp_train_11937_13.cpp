#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:167772160000")
using namespace std;
vector<pair<long long, long long> > tables;
long long oneSum = 0;
long long zeroSum = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < 4; i++) {
    char tmp;
    int missO = 0, missZ = 0;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        cin >> tmp;
        int sum = j + k;
        if (sum % 2 == 0) {
          missO += (tmp == '0');
          missZ += (tmp == '1');
        } else {
          missO += (tmp == '1');
          missZ += (tmp == '0');
        }
      }
    }
    oneSum += missO;
    zeroSum += missZ;
    tables.push_back(make_pair(missO, missZ));
  }
  long long ans = 999999999999;
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      int miss = tables[i].first + tables[j].first;
      int left = zeroSum - (tables[i].second + tables[j].second);
      ans = min(ans, (long long)miss + (long long)left);
    }
  }
  cout << ans;
  return 0;
}
