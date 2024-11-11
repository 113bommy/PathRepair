#include <bits/stdc++.h>
using namespace std;
struct st {
  int o;
  int e;
} arr[101];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, b;
  cin >> n >> b;
  vector<long long> vec;
  int v;
  arr[0].o = 0;
  arr[0].e = 0;
  for (int i = 0; i < n; i++) {
    cin >> v;
    vec.push_back(v);
    arr[i + 1] = arr[i];
    if (v & 1) {
      arr[i + 1].o++;
    } else {
      arr[i + 1].e++;
    }
  }
  vector<long long> vv;
  for (int i = 1; i < n; i++) {
    if (arr[i].o == arr[i].e) {
      vv.push_back(vec[i] - vec[i - 1]);
    }
  }
  int t = 0;
  int ans = 0;
  sort(vv.begin(), vv.end());
  for (int i = 0; i < (int)vv.size(); i++) {
    t += vv[i];
    if (t > b) {
      break;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
