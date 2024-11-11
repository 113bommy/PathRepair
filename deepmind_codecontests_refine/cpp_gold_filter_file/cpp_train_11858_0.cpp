#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
void pr(vector<int> output,int n, int sum,int m){
  if(sum==n){
    bool f = false;
    REP(i,output.size()){
      if(f) cout<<" ";
      f = true;
      cout<<output[i];
    }
    cout<<endl;
  }
  for(int i=min(n-sum,m); i>0; i--){
    vector<int> tmp;
    tmp = output;
    tmp.push_back(i);
    pr(tmp,n,sum+i,i);
  }
}
int main(void){
  int n;
  while(cin>>n){
    if(n==0) break;
    vector<int> emp;
    pr(emp,n,0,n);
  }   
  return 0;
}