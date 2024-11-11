#include <bits/stdc++.h>
using namespace std;
int n;
string s, t;
int cnt1, cnt2;
vector<int> p;
vector<int> np;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  cin >> s;
  cin >> t;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a' && t[i] == 'b') {
      cnt1++;
      p.push_back(i + 1);
    }
    if (s[i] == 'b' && t[i] == 'a') {
      cnt2++;
      np.push_back(i + 1);
    }
  }
  if ((cnt1 + cnt2) % 2 == 0) {
    cout << (cnt1 % 2 + cnt2 % 2) + (cnt1 - cnt1 % 2) / 2 +
                (cnt2 - cnt2 % 2) / 2
         << endl;
    for (int i = 0; i < p.size() - p.size() % 2; i += 2) {
      cout << p[i] << " " << p[i + 1] << endl;
    }
    for (int i = 0; i < np.size() - np.size() % 2; i += 2) {
      cout << np[i] << " " << np[i + 1] << endl;
    }
    if (p.size() % 2 == 1) {
      cout << p[p.size() - 1] << " " << p[p.size() - 1] << endl;
      cout << p[p.size() - 1] << " " << np[np.size() - 1] << endl;
    }
  } else
    cout << "-1\n";
  return 0;
}
