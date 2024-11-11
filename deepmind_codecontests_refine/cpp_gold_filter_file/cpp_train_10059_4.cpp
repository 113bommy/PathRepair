#include <bits/stdc++.h>
using namespace std;
struct TreeNode {};
bool comp() { return true; }
class qcomp {
 public:
  bool operator()() { return true; }
};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  string s;
  cin >> s;
  long long int n = s.size();
  vector<long long int> ap(n), bp(n);
  for (long long int i = 0; i < n; i++) {
    if (i == 0) {
      ap[i] = (s[i] == 'a');
      bp[i] = (s[i] == 'b');
      continue;
    }
    ap[i] = (s[i] == 'a') + ap[i - 1];
    bp[i] = (s[i] == 'b') + bp[i - 1];
  }
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = n - 1; j >= i; j--) {
      ans =
          max(ans, ap[n - 1] - ap[j] + ap[i] + bp[j] - (i > 0 ? bp[i - 1] : 0));
    }
  }
  cout << ans << "\n";
  return 0;
}
