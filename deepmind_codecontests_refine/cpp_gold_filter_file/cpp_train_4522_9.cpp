#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  string t;
  cin >> s;
  cin >> t;
  string ans;
  vector<int> num;
  if (t[0] >= s[0] && t[1] >= s[1]) {
    while (t[0] != s[0] && t[1] != s[1]) {
      num.push_back(2);
      ans += "RU";
      s[0]++;
      s[1]++;
    }
    while (t[0] > s[0]) {
      num.push_back(1);
      ans += "R";
      s[0]++;
    }
    while (t[1] > s[1]) {
      num.push_back(1);
      ans += "U";
      s[1]++;
    }
  } else if (t[0] >= s[0] && t[1] <= s[1]) {
    while (t[0] != s[0] && t[1] != s[1]) {
      num.push_back(2);
      ans += "RD";
      s[0]++;
      s[1]--;
    }
    while (t[0] > s[0]) {
      num.push_back(1);
      ans += "R";
      s[0]++;
    }
    while (t[1] < s[1]) {
      num.push_back(1);
      ans += "D";
      s[1]--;
    }
  } else if (t[0] <= s[0] && t[1] >= s[1]) {
    while (t[0] != s[0] && t[1] != s[1]) {
      num.push_back(2);
      ans += "LU";
      s[0]--;
      s[1]++;
    }
    while (t[0] < s[0]) {
      num.push_back(1);
      ans += "L";
      s[0]--;
    }
    while (t[1] > s[1]) {
      num.push_back(1);
      ans += "U";
      s[1]++;
    }
  } else if (t[0] <= s[0] && t[1] <= s[1]) {
    while (t[0] != s[0] && t[1] != s[1]) {
      num.push_back(2);
      ans += "LD";
      s[0]--;
      s[1]--;
    }
    while (t[0] < s[0]) {
      num.push_back(1);
      ans += "L";
      s[0]--;
    }
    while (t[1] < s[1]) {
      num.push_back(1);
      ans += "D";
      s[1]--;
    }
  }
  int k = 0;
  cout << num.size() << endl;
  for (int i = 0; i < num.size(); i++) {
    while (num[i] > 0) {
      cout << ans[k++];
      num[i]--;
    }
    cout << endl;
  }
}
