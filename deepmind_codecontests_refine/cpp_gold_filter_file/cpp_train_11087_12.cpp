#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <typename T1, typename T2>
void mapped(map<T1, T2> m) {
  for (auto ite = m.begin(); ite != m.end(); ++ite) {
    cout << "'" << ite->first << "'"
         << " : " << ite->second << endl;
  }
}
template <typename T1, typename T2>
void mappedArr(map<T1, vector<T2>> m) {
  for (auto ity = m.begin(); ity != m.end(); ++ity) {
    cout << "'" << ity->first << "'"
         << " : "
         << "[";
    for (int i = 0; i < (int)ity->second.size(); ++i) {
      (i == (int)ity->second.size() - 1) ? cout << ity->second[i]
                                         : cout << ity->second[i] << ",";
    }
    cout << "]" << endl;
  }
}
string int_to_string(int x) {
  stringstream ss;
  ss << x;
  string ni = ss.str();
  return ni;
}
int char_to_int(char c) {
  int n = (int)c - 48;
  return n;
}
int string_to_int(string x) {
  int n;
  stringstream s(x);
  s >> n;
  return n;
}
char upperCase(char a) {
  int d = (int)a - 97 + 65;
  char c = (char)d;
  return c;
}
char lowerCase(char a) {
  int d = (int)a - 65 + 97;
  char c = (char)d;
  return c;
}
bool isInt(char a) {
  int d = (int)a - 48;
  if (d >= 0 && d <= 9) {
    return true;
  }
  return false;
}
template <typename T1, typename T2>
void ArrPair(vector<pair<T1, T2>> vp) {
  for (int i = 0; i < (int)vp.size(); ++i) {
    cout << "(" << vp[i].first << "," << vp[i].second << ")" << endl;
  }
}
const int MOD = 1e9 + 7;
const long long INF = 1e18L + 5;
unordered_map<int, int> um;
unordered_set<int> us;
set<int> s;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int maxm = v[n - 1] - 1;
  vector<int> ans;
  for (int i = n - 1; i >= 0; --i) {
    int w = v[i] - maxm;
    if (w > 0) {
      ans.push_back(0);
    } else {
      int k = abs(w) + 1;
      ans.push_back(k);
    }
    maxm = max(maxm, v[i]);
  }
  for (int i = (int)ans.size() - 1; i >= 0; --i) {
    cout << ans[i] << " ";
  }
}
