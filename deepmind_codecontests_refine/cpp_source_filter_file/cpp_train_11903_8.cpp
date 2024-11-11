#include <bits/stdc++.h>
using namespace std;
const long int z = 1000000007;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int k, j;
  long long c = 0, sum = 0;
  cin >> k;
  string s;
  cin >> s;
  vector<long long> v;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1') {
      v.push_back(c);
      c = 0;
      continue;
    }
    c++;
  }
  v.push_back(c);
  if (k == 0) {
    for (auto x : v) sum += (x * (x + 1)) / 2;
  } else {
    for (int i = 0; i < v.size(); i++) {
      j = i + k;
      if (j < v.size()) sum += (v[i] + 1) * (v[j] + 1);
      if (j >= s.length() - 1) break;
    }
  }
  cout << sum;
}
