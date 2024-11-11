#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <typename T1>
void print(vector<T1> arr) {
  int l = (int)arr.size();
  cerr << "[";
  for (int i = 0; i < l; i++) {
    (i == l - 1) ? cerr << arr[i] : cerr << arr[i] << ",";
  }
  cerr << "]"
       << "\n";
}
template <typename T1>
void printArr(int arr[], int l) {
  cerr << "[";
  for (int i = 0; i < (int)l; i++) {
    (i == l - 1) ? cerr << arr[i] : cerr << arr[i] << ",";
  }
  cerr << "]"
       << "\n";
}
template <typename T1>
void console(vector<vector<T1>> arr) {
  for (int i = 0; i < (int)arr.size(); ++i) {
    cerr << "\n"
         << " [";
    for (int j = 0; j < (int)arr[i].size(); ++j) {
      (j == (int)arr[i].size() - 1) ? cerr << arr[i][j]
                                    : cerr << arr[i][j] << ",";
    }
    cerr << "]";
  }
  cerr << "\n";
}
template <typename T1, typename T2>
void mapped(map<T1, T2> m) {
  for (auto ite = m.begin(); ite != m.end(); ++ite) {
    cerr << "'" << ite->first << "'"
         << " : " << ite->second << "\n";
  }
}
template <typename T1, typename T2>
void mappedArr(map<T1, vector<T2>> m) {
  for (auto ity = m.begin(); ity != m.end(); ++ity) {
    cerr << "'" << ity->first << "'"
         << " : "
         << "[";
    for (int i = 0; i < (int)ity->second.size(); ++i) {
      (i == (int)ity->second.size() - 1) ? cerr << ity->second[i]
                                         : cerr << ity->second[i] << ",";
    }
    cerr << "]"
         << "\n";
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
template <typename T1, typename T2>
void vectPair(vector<pair<T1, T2>> vp) {
  for (int arrp = 0; arrp < (int)vp.size(); ++arrp) {
    cerr << "(" << vp[arrp].first << "," << vp[arrp].second << ")"
         << "\n";
  }
}
const int MOD = 1e9 + 7;
const long long INF = 1e18L + 5;
long long arr[26][26];
long long v[26];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  cin >> s;
  long long n = (int)s.size();
  if (n == 1) {
    cout << 1;
    return 0;
  }
  for (long long i = 0; i < n; ++i) {
    v[s[i] - 'a']++;
  }
  for (long long i = 0; i < 26; ++i) {
    long long p = 0;
    for (int j = 0; j < n; ++j) {
      int a = s[j] - 'a';
      if (a == i) {
        p++;
        arr[i][a]++;
      } else {
        arr[i][a] += p;
      }
    }
  }
  long long maxm = 0;
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      maxm = max(maxm, arr[i][j]);
    }
  }
  for (int i = 0; i < 26; ++i) {
    long long op = (v[i] * (v[i] - 1)) / 2;
    maxm = max(maxm, op);
  }
  cout << maxm;
  return 0;
}
