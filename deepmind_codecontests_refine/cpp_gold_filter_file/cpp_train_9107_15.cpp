#include <bits/stdc++.h>
using namespace std;
long long n, m, k, t, x, y, z, w, ct, ans, f;
string s, l;
long long arr[200005];
set<long long> si;
queue<long long> qi;
map<long long, long long> mi;
vector<long long> vi;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    while (arr[i] % 3 == 0) arr[i] /= 3;
    while (arr[i] % 2 == 0) arr[i] /= 2;
    if (i > 0 && arr[i] != arr[i - 1]) {
      cout << "No"
           << "\n";
      return 0;
    }
  }
  cout << "Yes"
       << "\n";
}
