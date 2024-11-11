#include <bits/stdc++.h>
using namespace std;
class Degugger;
class Debugger {
 public:
  template <class T>
  static void printVector(vector<T> &v, char separator = '\n') {
    for (T &element : v) cerr << element << separator;
    cerr << endl;
  }
  template <class T>
  static void printStates(vector<T> &memo) {
    printVector(memo);
  }
  template <class T>
  static void printStates(vector<vector<T> > &memo) {
    for (int i = 0; i < memo.size(); ++i) {
      for (int j = 0; j < memo[i].size(); ++j)
        cerr << "(" << i << "," << j << ")"
             << "=" << memo[i][j] << '\t';
      cerr << endl;
    }
  }

 private:
  Debugger() {}
};
class Problem {
  long long n;
  string s;

 public:
  void readInput() { cin >> s; }
  long long helper() {
    long long ans = 0;
    long long sum = 0;
    long long prev = 0;
    for (int i = 0; i < s.size(); ++i) {
      sum += (s[i] == '+' ? 1 : -1);
      long long cur = sum + prev;
      if (cur < 0) {
        ans += prev + 1;
        prev++;
      }
    }
    return ans + s.size();
  }
  void solveInstance() {
    readInput();
    cout << (helper()) << endl;
  }

 private:
};
int main() {
  int t;
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    Problem p;
    p.solveInstance();
  }
  return 0;
}
