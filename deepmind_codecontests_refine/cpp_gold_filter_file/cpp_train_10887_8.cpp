#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<T> &v) {
  for (typename vector<T>::size_type i = 0; i < v.size(); ++i)
    out << v[i] << " ";
  out << "\n";
  return out;
}
template <typename T, typename N>
std::ostream &operator<<(std::ostream &out, vector<pair<T, N> > &v) {
  for (size_t i = 0; i < v.size(); ++i)
    out << "(" << v[i].first << ", " << v[i].second << ") ";
  out << "\n";
  return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<vector<T> > &v) {
  for (size_t i = 0; i < v.size(); ++i) {
    for (size_t j = 0; j < v[i].size(); ++j) {
      out << v[i][j] << " ";
    }
    out << "\n";
  }
  return out;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<string> effective(n - k + 1);
  for (int i = 0; i < n - k + 1; ++i) {
    cin >> effective[i];
  }
  vector<string> names(50 + 1);
  string curr = "A";
  for (int i = 0; i <= 50; ++i) {
    names[i] = curr;
    ++curr[curr.size() - 1];
    if (curr == "Z") {
      curr = "Aa";
    }
  }
  vector<string> soldiers;
  for (int i = 0; i < k; ++i) {
    soldiers.push_back(names[i]);
  }
  int next = k;
  if (effective[0] == "NO") {
    soldiers[k - 1] = soldiers[0];
    --next;
  }
  for (int i = 1; i < n - k + 1; ++i) {
    if (effective[i] == "YES") {
      soldiers.push_back(names[next]);
      ++next;
    } else {
      string redundant = soldiers[soldiers.size() - k + 1];
      soldiers.push_back(redundant);
    }
  }
  cout << soldiers;
  return 0;
}
