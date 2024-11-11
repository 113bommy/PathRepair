3 #include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
Int a[216000];
Int n, m;

bool ok(int border){
  Int sum = (border + n) * 2 - 1;
  for(int j = border * 2;j < 2*n;j++){
    if(a[j] + a[sum - j] < m)return false;
  }
  return true;
}

int main(){
  cin >> n >> m;
  for(int i = 0;i < n * 2;i++){
    cin >> a[i];
  }
  sort(a, a + n);
  int bottom = 0, top = n;
  if(ok(0))top = 0;
  while(top - bottom > 1){
    int mid = (top + bottom) / 2;
    if(ok(mid))top = mid;
    else bottom = mid;
  }
  Int res = 0;
  for(int i = 0;i < 2*n;i++){
    if(i < 2 * top){
      res = max(res, (a[i] + a[2 * top - 1 - i]) % m);
    }
    else{
      res = max(res, (a[i] + a[ 2 * (n + top) - 1 - i]) % m);
    }
  }
  cout << res << endl;
  return 0;
}