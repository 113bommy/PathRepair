#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
inline long long toll(string s) {
  long long v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
vector<int> dfs_num;
vector<vector<int> > g;
vector<int> color;
vector<int> indegree;
vector<int> ts;
vector<int> num;
int n;
bool isCorrect() {
  bool flag = true;
  for (int i = 0; i < num.size(); i++) {
    if (num[i] != i) {
      flag = false;
    }
    if (i % 2 == 0) {
      num[i] = (num[i] + 1) % n;
    } else {
      num[i]--;
      if (num[i] < 0) {
        num[i] = n - 1;
      }
    }
  }
  return flag;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  num.clear();
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    num.push_back(x);
  }
  if (n == 1 && num[0] == 0) {
    cout << "Yes" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (isCorrect()) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
