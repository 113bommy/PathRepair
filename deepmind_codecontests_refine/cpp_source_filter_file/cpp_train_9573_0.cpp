#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

int main() {
  int n,m;
  while(cin>>n>>m, n||m) {
    string s[n];
    int a[n];

    REP(i,n) {
      cin >> s[i] >> a[i];
    }
    int res = 0;
    REP(i,m) {
      string b;
      cin >> b;
      REP(k, n) {
        bool f = 1;
        REP(j, 8) {
          if (s[k][j] != '*' && s[k][j] != b[j]){
            f = 0;
            break;
          }
        }
        if (f) {h
          res += a[k];
        }
      }
    }
    cout << res << endl;
  }
}