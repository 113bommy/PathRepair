#include <bits/stdc++.h>
using namespace std;
string s[110 * 110];
vector<string> v;
char sub(string s1, string s2) {
  int dem[30];
  memset(dem, 0, sizeof(dem));
  for (int i = 0; i < s1.size(); i++) dem[s1[i] - 'a']++;
  for (int i = 0; i < s2.size(); i++) dem[s2[i] - 'a']--;
  for (int i = 0; i <= 'z' - 'a'; i++)
    if (dem[i] == 1) return char(i + 'a');
}
bool cmp(string s1, string s2) { return (s1.length() > s2.length()); }
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "?"
         << " " << 1 << " " << 1 << endl;
    cout.flush();
    string s;
    cin >> s;
    cout << s;
    return 0;
  }
  cout << "?"
       << " " << 1 << " " << n - 1 << endl;
  cout.flush();
  int t = (n * (n - 1)) / 2;
  map<string, int> ma;
  for (int i = 1; i <= t; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ma[s]++;
  }
  cout << "?"
       << " " << 1 << " " << n << endl;
  cout.flush();
  t = (n * (n + 1)) / 2;
  for (int i = 1; i <= t; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (ma[s] > 0)
      ma[s]--;
    else
      v.push_back(s);
  }
  sort(v.begin(), v.end(), cmp);
  cout << "! ";
  for (int i = 0; i < v.size() - 1; i++) cout << sub(v[i], v[i + 1]);
  cout << v.back();
  return 0;
}
