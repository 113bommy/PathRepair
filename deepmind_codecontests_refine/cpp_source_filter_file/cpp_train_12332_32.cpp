#include <bits/stdc++.h>
using namespace std;
int R = pow(10, 9) + 7;
template <typename T>
void print(vector<T>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
template <typename T1, typename T2>
void print(vector<pair<T1, T2>>& v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    cout << "(" << v[i].first << "," << v[i].second << "),";
  }
  cout << "]" << endl;
}
template <typename T>
void print(vector<vector<T>>& v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    print(v[i]);
  }
  cout << "]" << endl;
}
template <typename T>
void print(set<T>& v) {
  cout << "{";
  for (auto i : v) {
    cout << i << " ";
  }
  cout << "}" << endl;
}
template <typename T1, typename T2>
void print(map<T1, T2>& v) {
  cout << "{";
  for (auto i : v) {
    cout << i.first << ":" << i.second << ",";
  }
  cout << "}" << endl;
}
template <typename T>
bool in(set<T>& indices, T x) {
  return indices.find(x) != indices.end();
}
template <typename T, typename T_>
bool in(map<T, T_>& indices, T x) {
  return indices.find(x) != indices.end();
}
int power(int x, int y) {
  int res = 1;
  x = x % R;
  if (x == 0) return 0;
  while (y > 0) {
    if (y % 2 == 1) res = (res * x) % R;
    y /= 2;
    x = (x * x) % R;
  }
  return res;
}
void TestCase() {
  map<string, int> val;
  cin >> val["S"];
  cin >> val["M"];
  cin >> val["L"];
  cin >> val["XL"];
  cin >> val["XXL"];
  map<string, vector<string>> neighbours;
  neighbours["S"] = {"S", "M", "L", "XL", "XXL"};
  neighbours["M"] = {"M", "L", "S", "XL", "XXL"};
  neighbours["L"] = {"L", "XL", "M", "S", "XXL"};
  neighbours["XL"] = {"XL", "XXL", "L", "M", "S"};
  neighbours["XXL"] = {"XXL", "XL", "L", "M", "S"};
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    string s;
    cin >> s;
    for (int i = 0; i < 5; i++) {
      if (val[neighbours[s][i]] > 0) {
        cout << neighbours[s][i] << "\n";
        val[neighbours[s][i]]--;
        break;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  T = 1;
  for (int tt = 1; tt <= T; tt++) {
    TestCase();
  }
}
