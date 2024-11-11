#include <bits/stdc++.h>
using namespace std;
string s;
int n;
vector<string> subs;
char l;
bool rep[10000010];
string mod(string data) {
  string y = "";
  for (int i = 0; i < data.size(); i++) {
    y += string(1, tolower(data[i]));
  }
  return y;
}
int main() {
  ios_base::sync_with_stdio(0);
  int k;
  cin >> k;
  for (int j = 0; j < k; j++) {
    string y;
    cin >> y;
    subs.push_back(mod(y));
  }
  sort(subs.rbegin(), subs.rend());
  cin >> s;
  cin >> l;
  n = s.size();
  string q = s;
  string low_s = mod(s);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < subs.size(); j++) {
      if (low_s.substr(i, subs[j].size()) == subs[j]) {
        for (int k = i; k < i + subs[j].size(); k++) {
          if (rep[k]) continue;
          rep[k] = true;
          q[k] = tolower(l);
          if (s[k] == tolower(l)) q[k] = (l == 'a') ? 'b' : 'a';
        }
        break;
      }
    }
  }
  for (int i = 0; i < s.size(); i++)
    if (isupper(s[i])) q[i] = toupper(q[i]);
  cout << q;
  return 0;
}
