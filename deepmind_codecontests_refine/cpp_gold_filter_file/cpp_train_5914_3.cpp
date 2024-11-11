#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k=0;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a.at(i);
  for(int j=1;j<n-1;j++){
    int x=a.at(j-1),y=a.at(j+1);
    if(a.at(j)>min(x,y)&&a.at(j)<max(x,y))k++;
  }
cout<<k<<endl;
}
