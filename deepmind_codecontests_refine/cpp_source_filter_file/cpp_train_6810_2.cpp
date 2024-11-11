#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int times[N];
string s;
int main() {
  while (cin >> s) {
    memset(times, 0, sizeof(times));
    for (int i = 0; i < s.size(); ++i) ++times[s[i] - '0'];
    --times[1];
    --times[6];
    --times[8];
    --times[9];
    int perm[] = {1, 6, 8, 9};
    int reminder = 0;
    vector<int> ans;
    for (int i = 1; i < 10; ++i)
      if (times[i]) {
        reminder = (reminder * 10 + i) % 7;
        ans.push_back(i);
        --times[i];
      }
    do {
      int value = 0;
      for (int i = 0; i < 4; ++i) value = 10 * value + perm[i];
      if ((reminder * 10000 + value) % 7 == 0) {
        for (int i = 0; i < ans.size(); ++i) cout << ans[i];
        cout << value;
        while (times[0]--) {
          cout << 0;
        }
        cout << endl;
        break;
      }
    } while (next_permutation(perm, perm + 4));
  }
  return 0;
}
