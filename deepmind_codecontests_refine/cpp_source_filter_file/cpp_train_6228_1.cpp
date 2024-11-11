#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,X,Y;
  cin>>n>>m>>X>>Y;
  vector<int> x(n+1);
  vector<int> y(m+1);
  for(int i=0;i<n;i++)cin>>x[i];
  for(int i=0;i<m;i++)cin>>y[j];
  x[n]=X; y[m]=Y;
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  if(x[n]<y[0]){ 
    cout<<"No War"<<endl;
  }
  else{
    cout<<"War"<<endl;
  }
}