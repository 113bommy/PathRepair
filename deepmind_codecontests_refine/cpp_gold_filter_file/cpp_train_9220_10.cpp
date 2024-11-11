#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.first << ", " << pair.second << ")";
}
int N;
pair<string, string> arr[109];
string s;
bool seen[109];
string home;
int main() {
  cin >> N;
  cin >> home;
  int pnt;
  for (int i = (1); i <= (N); ++i) {
    cin >> s;
    pnt = 0;
    while (s[pnt] != '-') pnt++;
    arr[i].first = s.substr(0, pnt);
    pnt += 2;
    arr[i].second = s.substr(pnt, s.length() - pnt);
  }
  string now = home;
  bool flag;
  while (1) {
    flag = 1;
    for (int i = (1); i <= (N); ++i)
      if (seen[i] == 0 && arr[i].first == now) {
        now = arr[i].second;
        flag = 0;
        seen[i] = 1;
        break;
      }
    if (flag) break;
  }
  if (home == now)
    cout << "home";
  else
    cout << "contest";
}
