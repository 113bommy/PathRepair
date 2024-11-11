#include <bits/stdc++.h>
using namespace std;
struct info {
  int ta = 0, gi = 0, piz = 0;
};
string q, s[101];
map<string, info> mp;
vector<string> a1, a2, a3;
bool taxi() {
  int nu;
  nu = q[0] - '0';
  for (int i = 1; i < q.size(); i++) {
    if (q[i] != '-' && (q[i] - '0') != nu) return false;
  }
  return true;
}
bool pizza() {
  int nu;
  nu = q[0] - '0';
  for (int i = 1; i < q.size(); i++) {
    if (q[i] != '-' && (q[i] - '0') >= nu) return false;
    if (q[i] != '-') nu = q[i] - '0';
  }
  return true;
}
int main() {
  int n, nn, m1 = 0, m2 = 0, m3 = 0;
  cin >> n;
  int ii = 0;
  for (int ii = 0; ii < n; ii++) {
    cin >> nn >> s[ii];
    for (int i = 0; i < nn; i++) {
      cin >> q;
      if (taxi())
        mp[s[ii]].ta++;
      else if (pizza())
        mp[s[ii]].piz++;
      else
        mp[s[ii]].gi++;
    }
    m1 = max(m1, mp[s[ii]].ta);
    m2 = max(m2, mp[s[ii]].piz);
    m3 = max(m3, mp[s[ii]].gi);
  }
  for (int i = 0; i < n; i++) {
    if (mp[s[i]].ta == m1) a1.push_back(s[i]);
    if (mp[s[i]].piz == m2) a2.push_back(s[i]);
    if (mp[s[i]].gi == m3) a3.push_back(s[i]);
  }
  cout << "If you want to call a taxi, you should call: ";
  for (int i = 0; i < a1.size(); i++) {
    if (i != a1.size() - 1)
      cout << a1[i] << ", ";
    else
      cout << a1[i] << '.';
  }
  cout << endl;
  cout << "If you want to order a pizza, you should call: ";
  for (int i = 0; i < a2.size(); i++) {
    if (i != a2.size() - 1)
      cout << a2[i] << ", ";
    else
      cout << a2[i] << '.';
  }
  cout << endl;
  cout
      << "If you want to go to a cafe with a wonderful girl, you should call: ";
  for (int i = 0; i < a3.size(); i++) {
    if (i != a3.size() - 1)
      cout << a3[i] << ", ";
    else
      cout << a3[i] << '.';
  }
  return 0;
}
