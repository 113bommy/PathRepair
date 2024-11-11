#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> st, en, len;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  string ss;
  cin >> n >> ss;
  for (int i = 0; i < n - 1; i++) {
    int s, e;
    if (ss[i] == 'G') {
      st.push_back(i);
      while (ss[i] == 'G' && ss[i + 1] == 'G') i++;
      en.push_back(i);
    }
  }
  if (!st.size()) {
    cout << 0 << endl;
    return 0;
  } else if (st.size() == 1) {
    cout << en[0] - st[0] + 1 << endl;
    return 0;
  } else if (st.size() == 2) {
    if (en[0] + 2 == st[1])
      len.push_back(en[1] - st[0]);
    else {
      len.push_back(en[0] - st[0] + 2);
      len.push_back(en[1] - st[1] + 2);
    }
  } else {
    for (int i = 0; i < st.size() - 1; i++) {
      if (en[i] + 2 == st[i + 1])
        len.push_back(en[i + 1] - st[i] + 1);
      else
        len.push_back(en[i] - st[i] + 2);
    }
    len.push_back(en[en.size() - 1] - st[st.size() - 1] + 2);
  }
  int maxnn = 0;
  for (int i = 0; i < len.size(); i++) maxnn = max(len[i], maxnn);
  cout << maxnn << endl;
  return 0;
}
