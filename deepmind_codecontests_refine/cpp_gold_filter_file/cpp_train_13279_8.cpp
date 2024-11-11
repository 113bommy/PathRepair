#include <bits/stdc++.h>
using namespace std;
long long MX = 9999999999;
long long n, m, l, t, k, e, fre = 0, c, total, nnn, yes, mx, mn = -1, r, xx, yy,
                            zz;
long long a[10];
string ss[] = {"S", "M", "L", "XL", "XXL", "XXXL"};
map<string, long long> num;
map<string, long long> wo, wow;
map<string, long long> koyta;
vector<string> all, check;
void dekhao() {
  cout << endl;
  for (int i = 0; i < 6; i++) {
    cout << num[ss[i]] << " ";
  }
  cout << endl;
  for (int i = 0; i < 5; i++) {
    cout << wo[ss[i]] << " ";
  }
  cout << endl;
}
void abardekhao() {
  cout << endl;
  for (int i = 0; i < 5; i++) {
    cout << koyta[ss[i]] << " ";
  }
  cout << endl;
}
int main() {
  for (int i = 0; i < 6; i++) {
    cin >> a[0];
    num[ss[i]] = a[0];
  }
  cin >> n;
  string second;
  for (int i = 0; i < n; i++) {
    cin >> second;
    all.push_back(second);
    if (second.find(',') == second.npos) {
      num[second]--;
      if (num[second] < 0) {
        cout << "NO" << endl;
        return 0;
      }
    } else {
      string o = second.substr(0, second.find(','));
      string p = second.substr(second.find(',') + 1, second.size());
      wo[o]++;
    }
  }
  for (int i = 0; i < 5; i++) {
    if (num[ss[i]] + num[ss[i + 1]] < wo[ss[i]]) {
      cout << "NO" << endl;
      return 0;
    } else {
      a[0] = min(num[ss[i]], wo[ss[i]]);
      koyta[ss[i] + "," + ss[i + 1]] = a[0];
      wo[ss[i]] -= a[0];
      num[ss[i + 1]] -= wo[ss[i]];
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    string w = all[i];
    if (w.find(',') == w.npos) {
      cout << w << endl;
    } else {
      string ag = w.substr(0, w.find(','));
      if (koyta[w] > 0) {
        koyta[w]--;
        cout << ag << endl;
      } else {
        cout << w.substr(w.find(',') + 1, w.size()) << endl;
      }
    }
  }
}
