#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    vector<int> v(k);
    for (auto i : a) v[i - 'A'] += 1;
    cout << *min_element((v).begin(), (v).end()) * k << "\n";
  }
  return 0;
}
