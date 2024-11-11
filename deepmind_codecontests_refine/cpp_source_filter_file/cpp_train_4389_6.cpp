#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a, s, d, i, j;
  string s1, s2;
  cin >> a >> s1 >> s2;
  vector<long long> vec;
  for (i = 0; i < a; i++) {
    vec.push_back((s1[i] - 'a') + (s2[i] - 'a'));
  }
  for (i = vec.size() - 1; i > 0; i--)
    if (vec[i] > 26) {
      vec[i - 1] += vec[i] / 26;
      vec[i] = vec[i] % 26;
    }
  for (i = 0; i < vec.size(); i++) {
    if (vec[i] % 2 == 1) vec[i + 1] += 26;
    vec[i] /= 2;
  }
  for (i = 0; i < vec.size(); i++) {
    char kk;
    kk = vec[i] + 'a';
    cout << kk;
  }
}
