#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,X,Y;
  cin>>n>>m>>X>>Y;
  vector<int> x(n), y(m);
  for(int i=0; i <n; ++i){
    cin>>x[i];
  }
  for(int i=0; i <m; ++i){
    cin>>y[i];
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  if(max(x[n-1], X)<min(y[0], Y)) cout<<"No War\n";
  else cout<<"War\n";
  return 0;
}
