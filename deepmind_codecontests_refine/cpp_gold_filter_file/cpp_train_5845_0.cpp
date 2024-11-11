#include <bits/stdc++.h>
using namespace std;
int n, m;
int hp[1000001];
pair<int, int> values[1000001];
int sum;
vector<pair<int, int>> group;
bool cmp(pair<int, int> &right, pair<int, int> &left) {
  return right.second < left.second;
}
void print(vector<int> a) {
  for (auto it : a) cout << it << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> hp[i];
    sum += hp[i];
  }
  int carry = 0;
  for (int i = 0; i < m; i++) {
    if (hp[i] - carry < 0) {
      carry -= hp[i];
      if (i != m - 1)
        values[i].first = n - carry;
      else
        values[i].first = n;
      values[i].second = i;
      continue;
    }
    int t = hp[i];
    hp[i] -= carry;
    if (i != m - 1)
      values[i].first = hp[i] % n;
    else
      values[i].first = n;
    values[i].second = i;
    carry = 0;
    if (hp[i] != 0) carry = n - hp[i] % n;
    hp[i] = t;
  }
  sort(values, values + m);
  for (int i = 0; i < m; i++)
    if (values[i].first != 0 &&
        (i == 0 || values[i].first != values[i - 1].first)) {
      int new_gr = 0;
      if (i == 0)
        new_gr = values[i].first;
      else
        new_gr = values[i].first - values[i - 1].first;
      group.push_back({new_gr, values[i].second});
    }
  while (group.size() < m) group.push_back({0, -1});
  cout << (sum + n - 1) / n << '\n';
  for (int i = 0; i < m; i++) cout << group[i].first << ' ';
  cout << '\n';
  carry = 0;
  vector<int> answer;
  for (int i = 0; i < m; i++) {
    if (hp[i] - carry < 0) {
      int here = n - carry;
      carry -= hp[i];
      int need = n - carry;
      for (int j = answer.size(); here < need; j++) {
        answer.push_back(i + 1);
        here += group[j].first;
      }
      continue;
    }
    if (carry != 0) {
      for (int j = answer.size(); j < m; j++) answer.push_back(i + 1);
      print(answer);
      answer.clear();
      hp[i] -= carry;
      carry = 0;
    }
    while (hp[i] - n >= 0) {
      for (int j = 0; j < m; j++) cout << i + 1 << ' ';
      cout << '\n';
      hp[i] -= n;
    }
    int need = hp[i];
    for (int here = 0, j = 0; here < need; j++) {
      answer.push_back(i + 1);
      here += group[j].first;
    }
    if (hp[i] != 0) carry = n - hp[i];
  }
  if (carry != 0) {
    for (int j = answer.size(); j < m; j++) answer.push_back(m);
    print(answer);
    answer.clear();
    carry = 0;
  }
  return 0;
}
