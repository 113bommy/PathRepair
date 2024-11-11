#include <bits/stdc++.h>
using namespace std;
int a[100005];
vector<int> v1, v2;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    if (a[i] > 1 && a[i - 1] > 1) {
      cout << "ambiguous\n";
      int cntp = 0;
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < a[j]; k++) {
          v1.push_back(cntp);
          v2.push_back(cntp);
        }
        if (j == i) v2[v2.size() - 1]++;
        cntp += (j == 0 ? 1 : a[j - 1]);
      }
      int sz = v1.size();
      for (int j = 0; j < sz; j++) cout << v1[j] << " ";
      cout << endl;
      for (int j = 0; j < sz; j++) cout << v2[j] << " ";
      return 0;
    }
  }
  cout << "perfect";
  return 0;
}
