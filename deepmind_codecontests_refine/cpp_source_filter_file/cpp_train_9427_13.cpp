#include <bits/stdc++.h>
using namespace std;
struct compare {
  bool operator()(const std::string& first, const std::string& second) {
    return first.size() > second.size();
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  int n, k, i;
  cin >> n >> k;
  string arr[110];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  string password;
  cin >> password;
  long long int tries = 0, equallen = 0;
  int plen = password.length();
  for (i = 0; i < n; i++) {
    if (arr[i].length() < plen) {
      tries++;
    } else if (arr[i].length() == plen) {
      equallen++;
    }
  }
  long long int ans = 0;
  ans = ((tries + 1) / k) * 5 + tries + 1;
  cout << ans << " ";
  ans = ((tries + equallen) / k) * 5 + (tries + equallen);
  cout << ans << endl;
  return 0;
}
