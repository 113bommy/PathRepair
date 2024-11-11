#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
  cin>>a>>b;
  vector<int>d(a,0);
  for(int i=0;i<b*2;i++){
    cin>>c;
    d[c-1]++;
  }
  for(int i=0;i<a;i++)cout<<d[i]<<endl;
}