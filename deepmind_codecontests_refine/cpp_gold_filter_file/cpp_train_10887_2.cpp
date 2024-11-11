#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void chkmin(T1 &first, T2 second) {
  if (first > second) first = second;
}
template <typename T1, typename T2>
inline void chkmax(T1 &first, T2 second) {
  if (first < second) first = second;
}
const string FileName = "input";
const int INF = 2e9;
const int MAXN = 1 << 18;
int n, k;
int id = 0;
vector<string> res;
vector<string> arr;
int main() {
  srand(time(0));
  ios::sync_with_stdio(0);
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      string s = "";
      s += 'A' + i;
      s += 'a' + j;
      res.push_back(s);
    }
  }
  cin >> n >> k;
  for (int i = 0; i < k - 1; ++i) {
    arr.push_back(res[id++]);
  }
  for (int i = k - 1; i < n; ++i) {
    string ans;
    cin >> ans;
    if (ans == "NO") {
      arr.push_back(arr[(int)arr.size() - k + 1]);
    } else {
      arr.push_back(res[id++]);
    }
  }
  for (string i : arr) {
    cout << i << ' ';
  }
}
