#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> vec;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string con;
    int num;
    cin >> con;
    if (con[0] == 'a') {
      cin >> num;
      vec.insert(lower_bound(vec.begin(), vec.end(), num), num);
    } else if (con[0] == 'd') {
      cin >> num;
      vec.erase(lower_bound(vec.begin(), vec.end(), num));
    } else {
      long long ans = 0;
      for (int k = 2; k < vec.size(); k += 5) {
        ans += vec[k];
      }
      cout << ans << endl;
    }
  }
  return 0;
}
