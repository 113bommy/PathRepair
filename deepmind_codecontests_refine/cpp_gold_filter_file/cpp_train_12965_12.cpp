#include <bits/stdc++.h>
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
using namespace std;
vector<vector<int> > g;
int p2[] = {4, 9, 25, 49, 81};
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  for (int i = 0; i < 5; i++) {
    cout << p2[i] << endl;
    fflush(stdout);
    cin >> str;
    if (str == "yes") {
      cout << "composite" << endl;
      fflush(stdout);
      return 0;
    }
  }
  int c = 0;
  for (int i = 0; i < 15; i++) {
    cout << p[i] << endl;
    fflush(stdout);
    cin >> str;
    if (str == "yes") c++;
    if (c >= 2) {
      cout << "composite" << endl;
      fflush(stdout);
      return 0;
    }
  }
  cout << "prime" << endl;
  fflush(stdout);
}
