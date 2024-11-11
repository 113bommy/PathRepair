#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k, count = 0;
  cin >> n >> k;
  while (n--) {
    string s;
    cin >> s;
    int lucky = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '4' || s[i] == '7') lucky++;
    }
    if (lucky <= k) count++;
  }
  cout << count;
  return 0;
}
