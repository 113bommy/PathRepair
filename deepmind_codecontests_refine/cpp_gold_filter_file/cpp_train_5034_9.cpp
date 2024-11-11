#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  int sum = 0;
  int l[n], dp1[n], dp2[n];
  for (int i = 0; i < n; i++) {
    cin >> l[i];
    sum += l[i];
  }
  if (sum % 3 != 0 || n < 3) {
    cout << 0 << endl;
    return 0;
  }
  dp1[0] = l[0];
  dp2[n - 1] = l[n - 1];
  for (int i = 1; i < n; i++) dp1[i] = l[i] + dp1[i - 1];
  for (int i = n - 2; i >= 0; i--) dp2[i] = l[i] + dp2[i + 1];
  vector<int> le;
  vector<int> ri;
  for (int i = 0; i < n - 2; i++)
    if (dp1[i] == sum / 3) le.push_back(i);
  for (int i = n - 1; i >= 2; i--)
    if (dp2[i] == sum / 3) ri.push_back(i);
  long long res = 0;
  map<int, int> cuantos;
  for (int i = 0; i < ri.size(); i++) cuantos[ri[i]] = ri.size() - i;
  reverse(ri.begin(), ri.end());
  vector<int>::iterator low;
  int i, j;
  for (i = 0, j = 0; i < le.size() && j < ri.size();) {
    if (le[i] + 1 >= ri[j])
      j++;
    else {
      res += (ri.size() - j);
      i++;
    }
  }
  cout << res << endl;
}
