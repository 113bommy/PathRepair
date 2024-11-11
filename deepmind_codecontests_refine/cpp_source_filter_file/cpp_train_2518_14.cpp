#include <bits/stdc++.h>
using namespace std;
string a, b;
int n;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> a >> b;
    n = a.length();
    vector<int> V;
    int cnt00 = 0, cnt01 = 0, cnt10 = 0, cnt11 = 0;
    for (int i = 0; i < n; i += 2) {
      if (a[i] == '0' && a[i + 1] == '1') cnt01++;
      if (a[i] == '0' && a[i + 1] == '0') cnt00++;
      if (a[i] == '1' && a[i + 1] == '0') cnt10++;
      if (a[i] == '1' && a[i + 1] == '1') cnt11++;
    }
    for (int i = 0; i < n; i += 2) {
      if (b[i] == '0' && b[i + 1] == '1') cnt10--;
      if (b[i] == '0' && b[i + 1] == '0') cnt00--;
      if (b[i] == '1' && b[i + 1] == '0') cnt01--;
      if (b[i] == '1' && b[i + 1] == '1') cnt11--;
    }
    if (cnt00 || cnt11) {
      puts("-1");
      continue;
    }
    int cnt = 0;
    int flag = 0;
    for (int i = 0; i < n; i += 2) {
      if (a[i] == '1' && a[i + 1] == '0') cnt++;
      if (a[i] == '0' && a[i + 1] == '1') cnt--;
      if (cnt10 == cnt) {
        V.push_back(i + 2);
        reverse(a.begin(), a.begin() + i + 2);
        break;
      }
    }
    if (!V.size()) {
      cnt = 0;
      for (int i = 0; i < n; i += 2) {
        if (b[i] == '1' && b[1 + i] == '0') cnt++;
        if (b[i] == '0' && b[i + 1] == '1') cnt--;
        if (cnt10 + cnt == 0) {
          flag = i + 2;
          reverse(b.begin(), b.begin() + i + 2);
          break;
        }
      }
    }
    for (int i = 0; i < n; i += 2) {
      char tmp1 = b[n - i - 2], tmp2 = b[n - i - 1];
      if (abs((int)tmp1 - (int)tmp2) == 1) swap(tmp1, tmp2);
      for (int j = i; j < n; j += 2) {
        if (a[j] == tmp1 && a[j + 1] == tmp2) {
          if (j) V.push_back(j);
          reverse(a.begin(), a.begin() + j);
          V.push_back(j + 2);
          reverse(a.begin(), a.begin() + j + 2);
          break;
        }
      }
    }
    if (flag) V.push_back(flag);
    cout << V.size() << endl;
    for (int i = 0; i < V.size(); i++) cout << V[i] << ' ';
    puts("");
  }
}
