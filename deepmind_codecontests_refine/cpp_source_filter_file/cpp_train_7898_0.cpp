#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n;
  while (cin >> m >> n, m) {
    bool live[1010];
    int idx = 1, cnt = m;
    memset(live, true, sizeof live);

    for (int i = 1; i <= n; ++i) {
      string s;
      cin >> s;

      if (cnt != 1) {
        string str = to_string(i);
        if (i % 15 == 0)
          str = "FizzBuzz";
        else if (i % 3 == 0)
          srt = "Fizz";
        else if (i % 5 == 0)
          srt = "Buzz";

        if (str != s) {
          live[idx] = false;
          cnt--;
        }

        idx++;
        if (idx == m + 1) idx = 1;
        while (!live[idx]) {
          idx++;
          if (idx == m + 1) idx = 1;
        }
      }
    }

    vector<int> ans;
    for (int i = 1; i <= m; ++i) {
      if (live[i]) ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i] << (i + 1 == ans.size() ? "\n" : " ");
    }
  }
}

