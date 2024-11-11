#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define F first
#define S second
#define INF 1 << 30

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int a[14], p;

int main(){
  char str[514];
  while(fgets(str, sizeof(str), stdin) && str[0] != '0'){
    memset(a, 0, sizeof(a));
    char *tp;
    tp = strtok(str, " ");
    while(tp != NULL){
      a[atoi(tp)]++;
      tp = strtok(NULL, " ");
    }

    //    rep(i, p) printf("%d ", a[i]); puts("");
    int res = 0;
    a[10] += a[11]; a[10] += a[12]; a[10] += a[13];
    REP(i, 2, 11) res += a[i]*i;
    //    printf("%d\n", res);
    //    printf("%d\n", a[1]);

    int one = 11*a[1];
    while(res+one > 21 && one != a[1]){
      one -= 10;
    }
    //    printf("%d\n", res+one);
    res += one;
    if(res > 21) res = 0;

    printf("%d\n", res);
  }
  return 0;
}