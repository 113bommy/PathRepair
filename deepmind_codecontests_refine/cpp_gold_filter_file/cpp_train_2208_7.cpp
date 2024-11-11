#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long len = s.size();
    vector<long long> v;
    for (long long i = 0; i < len; i++) {
      long long c = 0;
      if (i + 5 <= len) {
        if (s.substr(i, 5) == "twone") v.push_back(i + 3), i += 4, c = 1;
      }
      if (i + 3 <= len && !c) {
        if (s.substr(i, 3) == "two") v.push_back(i + 2);
        if (s.substr(i, 3) == "one") v.push_back(i + 2);
      }
    }
    long long l = v.size();
    cout << l << "\n";
    for (long long i = 0; i < l; i++) cout << v[i] << " ";
    cout << "\n";
  }
}
