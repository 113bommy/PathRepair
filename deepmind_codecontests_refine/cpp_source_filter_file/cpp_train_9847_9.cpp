#include <bits/stdc++.h>
using namespace std;
vector<int> parse(string str, unordered_map<string, vector<int>> &m,
                  const vector<int> &given) {
  if (str == "?")
    return given;
  else if (m.count(str))
    return m[str];
  else {
    vector<int> a;
    for (int i = 0; i < str.length(); i++) a.push_back(str[i] - '0');
    return a;
  }
}
vector<int> aand(const vector<int> &a, const vector<int> &b) {
  int m = a.size();
  vector<int> c(m);
  for (int i = 0; i < m; i++) c[i] = a[i] & b[i];
  return c;
}
vector<int> oor(const vector<int> &a, const vector<int> &b) {
  int m = a.size();
  vector<int> c(m);
  for (int i = 0; i < m; i++) c[i] = a[i] | b[i];
  return c;
}
vector<int> xxor(const vector<int> &a, const vector<int> &b) {
  int m = a.size();
  vector<int> c(m);
  for (int i = 0; i < m; i++) c[i] = a[i] ^ b[i];
  return c;
}
int main() {
  int n, m;
  cin >> n >> m;
  string line;
  getline(cin, line);
  vector<string> assignments(n);
  for (int i = 0; i < n; i++) getline(cin, assignments[i]);
  vector<vector<int>> attempts(2, vector<int>(m, 0));
  for (int i = 0; i < m; i++) attempts[1][i] = 1;
  vector<vector<int>> results(2, vector<int>(m, 0));
  for (int i = 0; i < attempts.size(); i++) {
    auto attempt = attempts[i];
    unordered_map<string, vector<int>> values;
    for (int j = 0; j < n; j++) {
      auto assignment = assignments[j];
      int pos = assignment.find(" := ");
      auto name = assignment.substr(0, pos);
      assignment = assignment.substr(pos + 4);
      vector<int> value;
      if ((pos = assignment.find(" AND ")) != string::npos) {
        auto left = parse(assignment.substr(0, pos), values, attempt);
        auto right = parse(assignment.substr(pos + 5), values, attempt);
        value = aand(left, right);
      } else if ((pos = assignment.find(" OR ")) != string::npos) {
        auto left = parse(assignment.substr(0, pos), values, attempt);
        auto right = parse(assignment.substr(pos + 4), values, attempt);
        value = oor(left, right);
      } else if ((pos = assignment.find(" XOR ")) != string::npos) {
        auto left = parse(assignment.substr(0, pos), values, attempt);
        auto right = parse(assignment.substr(pos + 5), values, attempt);
        value = xxor(left, right);
      } else {
        value = parse(assignment, values, attempt);
      }
      values.insert(make_pair(name, value));
    }
    vector<int> result(m, 0);
    for (auto value : values)
      for (int j = 0; j < m; j++) result[j] += value.second[j];
    results[i] = result;
  }
  string ans1 = "", ans2 = "";
  for (int i = 0; i < m; i++)
    if (results[0][i] < results[1][i]) {
      ans1 += '1';
      ans2 += '0';
    } else if (results[0][i] > results[1][i]) {
      ans1 += '0';
      ans2 += '1';
    } else {
      ans1 += '0';
      ans2 += '0';
    }
  cout << ans1 << endl;
  cout << ans2 << endl;
  return 0;
}
