#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T>
void cprintv(vector<T>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
template <class T, class U>
void cprintd(unordered_map<T, U> tp) {
  for (auto i = tp.begin(); i != tp.end(); i++) {
    cout << i->first << ": " << i->second << endl;
  }
}
template <class T = ll>
vector<T> clist(int n) {
  std::vector<T> v;
  while (n--) {
    T k;
    cin >> k;
    v.push_back(k);
  }
  return v;
}
vector<char> cstrtv(string& s) {
  vector<char> v;
  for (int i = 0; i < s.size(); i++) {
    v.push_back(s[i]);
  }
  return v;
}
template <class T>
unordered_map<T, int> ccount(vector<T>& v) {
  unordered_map<T, int> m;
  for (int i = 0; i < v.size(); i++) {
    m[v[i]] += 1;
  }
  return m;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> scores;
  for (int i = 0; i < m; i++) {
    vector<int> k(5);
    scores.push_back(k);
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'A') {
        scores[j][0]++;
      }
      if (s[j] == 'B') {
        scores[j][1]++;
      }
      if (s[j] == 'C') {
        scores[j][2]++;
      }
      if (s[j] == 'D') {
        scores[j][3]++;
      }
      if (s[j] == 'E') {
        scores[j][4]++;
      }
    }
  }
  int final = 0;
  vector<int> v = clist<int>(m);
  for (int k = 0; k < m; k++) {
    int maxy = 0;
    for (int f = 0; f < 5; f++) {
      if (scores[k][f] > maxy) {
        maxy = scores[k][f];
      }
    }
    final += maxy * v[k];
  }
  cout << final << endl;
}
