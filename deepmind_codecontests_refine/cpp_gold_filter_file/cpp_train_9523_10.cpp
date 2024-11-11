#include <bits/stdc++.h>
using namespace std;
void solveproblem();
int main(int argc, char** argv) {
  int testcasescount;
  testcasescount = 1;
  for (int testcase = 0; testcase < testcasescount; testcase++) {
    solveproblem();
    if (testcase < testcasescount - 1) cout << endl;
  }
  return 0;
}
void solveproblem() {
  int n;
  long long m;
  cin >> n >> m;
  long long cnt = 2ll << (n - 2);
  vector<int> b, e;
  for (int i = 1; i < n; i++) {
    if (m > cnt / 2) {
      e.push_back(i);
      m -= cnt / 2;
    } else
      b.push_back(i);
    cnt /= 2;
  }
  for (int i = 0; i < b.size(); i++) {
    cout << b[i] << ' ';
  }
  cout << n;
  for (int i = e.size() - 1; i >= 0; i--) {
    cout << ' ' << e[i];
  }
}
