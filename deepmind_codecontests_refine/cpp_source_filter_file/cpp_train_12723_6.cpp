#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, const string& delim = " ") {
  vector<string> res;
  string t;
  for (int i = 0; i != s.size(); i++) {
    if (delim.find(s[i]) != string::npos) {
      if (!t.empty()) {
        res.push_back(t);
        t = "";
      }
    } else {
      t += s[i];
    }
  }
  if (!t.empty()) {
    res.push_back(t);
  }
  return res;
}
vector<int> splitInt(const string& s, const string& delim = " ") {
  vector<string> tok = split(s, delim);
  vector<int> res;
  for (int i = 0; i != tok.size(); i++) res.push_back(atoi(tok[i].c_str()));
  return res;
}
template <typename T>
void print(T a) {
  cerr << a;
}
static void print(long long a) { cerr << a << "L"; }
static void print(string a) { cerr << '"' << a << '"'; }
template <typename T>
void print(vector<T> a) {
  cerr << "{";
  for (int i = 0; i != a.size(); i++) {
    if (i != 0) cerr << ", ";
    print(a[i]);
  }
  cerr << "}" << endl;
}
int main() {
  int n, arr[100005];
  while (scanf("%d", &n) != EOF) {
    for (int i = 0, _n = (n); i < _n; i++) scanf("%d", arr + i);
    sort(arr, arr + n);
    vector<int> num, freq;
    num.push_back(arr[0]);
    freq.push_back(1);
    for (int i = (1), _n = (n - 1); i <= _n; i++) {
      if (num.back() != arr[i]) {
        num.push_back(arr[i]);
        freq.push_back(1);
      } else
        freq.back()++;
    }
    print(num);
    print(freq);
    bool can = 1;
    for (int i = 0, _n = (num.size() - 1); i < _n; i++) {
      if (num[i + 1] - num[i] > 1) can = false;
      int x = min(freq[i], freq[i + 1]);
      can &= x;
      freq[i] -= x;
      freq[i + 1] -= x;
    }
    for (int i = 0, _n = (freq.size()); i < _n; i++) can &= (freq[i] == 0);
    puts(can ? "YES" : "NO");
  }
  return 0;
}
