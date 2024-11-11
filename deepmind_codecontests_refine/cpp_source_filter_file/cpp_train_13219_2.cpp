#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>
#include<numeric>
#include<queue>
using namespace std;

long long int mod = 1000000007;

int main(void) {

  int n, m, t;
  cin >> n >> m >> t;

  vector<bool> a(10000+5, false);
  for(int i=1; i<n+1; i++){
    int tmp;
    cin >> tmp;
    for(int j=max(0, tmp-m); j<min(a.size(), tmp+m); j++) a[j] = true;
  }

  int cnt = 0;
  for(int i=0; i<t; i++){
    cnt += a[i];
  }
  cout << t - cnt << endl;

  return 0;
}





//