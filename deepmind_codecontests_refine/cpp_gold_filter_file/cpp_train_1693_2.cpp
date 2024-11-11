#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string src, dest;
    cin >> src >> dest;
    vector<long long> opr;
    long long idx = 0;
    for (long long i = n - 1; i >= 0; i--) {
      if (dest[i] == src[idx]) {
        opr.push_back(1);
        opr.push_back(i + 1);
        if (i > 0) opr.push_back(i);
      } else {
        opr.push_back(i + 1);
        if (i > 0) opr.push_back(i);
      }
      idx++;
    }
    cout << opr.size() << " ";
    for (auto it : opr) cout << it << " ";
    cout << "\n";
  }
}
