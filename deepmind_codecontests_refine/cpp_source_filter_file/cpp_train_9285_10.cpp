#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tttt = 1;
  for (int tt = 0; tt < tttt; tt++) {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      v.push_back(temp);
    }
    sort(v.begin(), v.end());
    long int sum1, sum2;
    sum1 = 0;
    sum2 = 0;
    if (v.size() == 1) {
      cout << v[0] * v[0] << endl;
      continue;
    }
    int i = 0;
    while (i < v.size() - 1 - i) {
      sum1 += v[i];
      sum2 += v[v.size() - 1 - i];
      i++;
    }
    if (i == v.size() - 1 - i) {
      sum2 += v[i];
    }
    cout << sum2 * sum2 + sum1 * sum1 << endl;
  }
}
