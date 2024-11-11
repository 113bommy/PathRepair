#include <bits/stdc++.h>
using namespace std;
int n;
map<string, vector<string> > E;
map<string, pair<long long, long long> > S;
map<string, pair<int, int> > BS;
map<string, char> T;
pair<long, long long> calc(string name) {
  if (S.count(name)) return S[name];
  long long xsum = 0, ysum = 0, xmax = 0, ymax = 0;
  int n = E[name].size();
  for (int i = 0; i < n; ++i) {
    pair<long long, long long> Size = calc(E[name][i]);
    xsum += Size.first;
    ysum += Size.second;
    xmax = max(xmax, Size.first);
    ymax = max(ymax, Size.second);
  }
  if (n == 0) {
    S[name] = make_pair(0, 0);
    return S[name];
  }
  if (T[name] == 'V')
    S[name] = make_pair(xmax + 2 * BS[name].first,
                        ysum + 2 * BS[name].first + (n - 1) * BS[name].second);
  else
    S[name] = make_pair(xsum + 2 * BS[name].first + (n - 1) * BS[name].second,
                        ymax + 2 * BS[name].first);
  return S[name];
}
int main() {
  int i, j, k;
  scanf("%d\n", &n);
  string s, t;
  while (n--) {
    cin >> s;
    if (s == "Widget") {
      cin >> t;
      string name = "";
      for (i = 0; i < t.size() && isalpha(t[i]); ++i) name += t[i];
      int x = 0, y = 0;
      for (i = i + 1; i < t.size() && isdigit(t[i]); ++i)
        x = x * 10 + t[i] - '0';
      for (i = i + 1; i < t.size() && isdigit(t[i]); ++i)
        y = y * 10 + t[i] - '0';
      S[name] = make_pair(1LL * x, 1LL * y);
      T[name] = 'W';
    } else if (s == "VBox" || s == "HBox") {
      cin >> t;
      BS[t] = make_pair(0, 0);
      if (s == "VBox")
        T[t] = 'V';
      else
        T[t] = 'H';
    } else {
      string name = "";
      for (i = 0; i < s.size() && isalpha(s[i]); ++i) name += s[i];
      string t = "";
      for (i = i + 1; i < s.size() && s[i] != '('; ++i) t += s[i];
      if (t == "pack") {
        string wname = "";
        for (i = i + 1; i < s.size() && isalpha(s[i]); ++i) wname += s[i];
        E[name].push_back(wname);
      } else {
        int x = 0;
        for (i = i + 1; i < s.size() && isdigit(s[i]); ++i)
          x = x * 10 + s[i] - '0';
        if (t == "set_border")
          BS[name] = make_pair(x, BS[name].second);
        else
          BS[name] = make_pair(BS[name].first, x);
      }
    }
  }
  for (map<string, char>::iterator it = T.begin(); it != T.end(); ++it) {
    s = (*it).first;
    pair<long long, long long> Size = calc(s);
    cout << s << " " << Size.first << " " << Size.second << endl;
  }
  return 0;
}
