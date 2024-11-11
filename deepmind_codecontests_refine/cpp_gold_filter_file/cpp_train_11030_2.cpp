#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  int N, M; cin >> N >> M;
  double L[N], a[N], b[N]; FOR(i,0,N) cin >> L[i] >> a[i] >> b[i];
  double ans = 0;
  FOR(i,0,1<<N) {
    vector<int> v;
    FOR(j,0,N) {
      if((i>>j)&1) v.push_back(j);
    }
    if((int)v.size() == M) {
      double mx = 0;
      FOR(j,0,M) {
        FOR(k,j+1,M) {
          mx += (L[v[k]] - L[v[j]]) * (L[v[k]] - L[v[j]]);
          mx += (a[v[k]] - a[v[j]]) * (a[v[k]] - a[v[j]]);
          mx += (b[v[k]] - b[v[j]]) * (b[v[k]] - b[v[j]]);
        }
      }
      ans = max(ans, mx);
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}