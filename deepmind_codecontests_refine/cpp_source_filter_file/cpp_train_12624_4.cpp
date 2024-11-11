#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    vector<vector<long long> > a(2);
    vector<long long> ans;
    long long n;
    string b;
    cin >> n >> b;
    long long cou = 1;
    for (char c : b) {
      long long x = c - '0';
      if (a[x].size() == 0) a[x].push_back(cou++);
      ans.push_back(a[x].back());
      a[!x].push_back(a[x].back());
      a[x].pop_back();
    }
    cout << cou << "\n";
    for (long long i : ans) cout << i << ' ';
    cout << "\n";
  }
  return 0;
}
