#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[100009];
int n;
vector<char> person;
bool in_between(int pos, int val) {
  if (pos >= p[val].first && pos <= p[val].second) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int start = 9999;
  int end = 0;
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x >> p[i].first >> p[i].second;
    person.push_back(x);
    start = min(start, p[i].first);
    end = max(end, p[i].second);
  }
  int c = 0;
  int ans = 0;
  for (int i = 1; i <= 400; i++) {
    c = 0;
    int male = 0;
    int female = 0;
    for (int j = 0; j < n; j++) {
      if (in_between(i, j)) {
        if (person[j] == 'M') male++;
        if (person[j] == 'F') female++;
        c++;
      }
    }
    ans = max(ans, min(male, female));
  }
  cout << ans;
  return 0;
}
