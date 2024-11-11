#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  for (auto vi : v) out << vi << ", ";
  out << "]\n";
  return out;
}
int n;
string s;
vector<int> d;
string solution() {
  int i = 0;
  while (0 <= i && i < n) {
    if (d[i] == -1) {
      return "INFINITE";
    }
    int j = i + d[i] * (s[i] == '>' ? 1 : -1);
    d[i] = -1;
    i = j;
  }
  return "FINITE";
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    d.push_back(temp);
  }
  cout << solution() << "\n";
  return 0;
}
