#include <bits/stdc++.h>
using namespace std;
long long int input(long long int n, vector<long long int> &ve);
long long int input(long long int n, vector<long long int> &ve) {
  long long int val;
  for (long long int i = 0; i < n; i++) {
    cin >> val;
    ve.push_back(val);
  }
  return 0;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, a, t;
  vector<long long int> v;
  cin >> t;
  while (t--) {
    cin >> n;
    string st;
    long long int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    vector<string> v1, v2;
    vector<long long int> v1i, v2i;
    set<string> s1, s2;
    for (long long int i = 0; i < n; i++) {
      cin >> st;
      long long int len = st.length();
      if (st[0] == '0' && st[len - 1] == '1') {
        cnt1++;
        v1.push_back(st);
        v1i.push_back(i + 1);
        s1.insert(st);
      }
      if (st[0] == '1' && st[len - 1] == '0') {
        cnt2++;
        v2.push_back(st);
        v2i.push_back(i + 1);
        s2.insert(st);
      }
      if (st[0] == '1' && st[len - 1] == '1') {
        cnt3++;
      }
      if (st[0] == '0' && st[len - 1] == '0') {
        cnt4++;
      }
    }
    if (cnt1 == 0 && cnt2 == 0) {
      if (cnt3 != 0 && cnt4 != 0) {
        cout << "-1" << endl;
      } else {
        cout << "0" << endl;
      }
      continue;
    }
    long long int ans = 0, flag = 0, p;
    vector<long long int> pp;
    if (cnt1 > cnt2) {
      p = cnt1 - cnt2;
      p = p / 2;
      for (long long int i = 0; i < v1.size(); i++) {
        if (p <= 0) {
          break;
        }
        string tt = v1[i];
        reverse(tt.begin(), tt.end());
        if (s2.find(tt) == s2.end()) {
          pp.push_back(v1i[i]);
          --p;
        }
      }
    } else if (cnt1 < cnt2) {
      p = cnt2 - cnt1;
      p = p / 2;
      for (long long int i = 0; i < v2.size(); i++) {
        if (p <= 0) {
          break;
        }
        string tt = v2[i];
        reverse(tt.begin(), tt.end());
        if (s1.find(tt) == s1.end()) {
          pp.push_back(v2i[i]);
          --p;
        }
      }
    }
    flag = p;
    if (flag == 0) {
      cout << (abs(cnt1 - cnt2)) / 2 << endl;
      for (long long int i = 0; i < pp.size(); i++) {
        cout << pp[i] << " ";
      }
      cout << endl;
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}
