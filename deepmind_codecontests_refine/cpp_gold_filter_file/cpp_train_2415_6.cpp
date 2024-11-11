#include <bits/stdc++.h>
using namespace std;
void taskA() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[1010] = {}, x, ma, ret = 0;
    for (int i = (1); i <= (n); i++) cin >> x, a[x]++;
    for (int i = (n); i >= (1); i--) {
      ret += a[i];
      if (ret >= i) {
        ma = i;
        break;
      }
    }
    cout << ma << endl;
  }
}
void taskB() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cin.get();
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int x = 0, y = 0, cnt = 0;
    for (int i = (0); i < (n); i++) {
      if (s1[i] != s2[i]) {
        cnt++;
        if (!x)
          x = i + 1;
        else if (!y)
          y = i + 1;
      }
    }
    if (x && y) {
      x--, y--;
      char c1 = s1[x], c2 = s2[y];
      s1[x] = c2, s2[y] = c1;
    }
    if ((cnt == 2 || cnt == 0) && s1 == s2)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
void taskC() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    string s1, s2;
    cin.get();
    cin >> s1 >> s2;
    int x = 0, y = 0, cnt = 0, cnt1[26] = {}, cnt2[26] = {};
    for (int i = (0); i < (n); i++) {
      cnt1[s1[i] - 'a']++;
      cnt1[s2[i] - 'a']++;
    }
    int flag = 0;
    for (int i = (0); i < (26); i++)
      if (cnt1[i] & 1) {
        flag = 1;
        break;
      }
    if (flag)
      cout << "No\n";
    else {
      if (s1 == s2) continue;
      vector<pair<int, int> > ans;
      for (int i = (0); i < (n); i++)
        for (int j = (i + 1); j < (n); j++) {
          if (s1[i] == s1[j]) {
            swap(s1[j], s2[i]);
            ans.push_back(make_pair(j, i));
            break;
          } else if (s1[i] == s2[j]) {
            swap(s2[j], s1[n - 1]);
            swap(s2[i], s1[n - 1]);
            ans.push_back(make_pair(n - 1, j));
            ans.push_back(make_pair(n - 1, i));
            break;
          }
        }
      assert(s1 == s2);
      cout << "Yes\n";
      cout << ans.size() << endl;
      for (int i = (0); i < (ans.size()); i++)
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
  }
}
void taskD() {
  long long n;
  cin >> n;
  long long q = sqrt(n), cnt = n;
  for (int i = (2); i <= (q); i++) {
    if (n % i) continue;
    while (n % i == 0) n /= i;
    if (n == 1)
      cout << i << endl;
    else
      cout << "1\n";
    return;
  }
  cout << n << endl;
}
int main() {
  taskD();
  return 0;
}
