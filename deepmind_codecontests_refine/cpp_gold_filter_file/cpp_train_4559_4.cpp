#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,m;cin>>a>>b>>m;
  	vector<int >ref(a,0),mic(b,0);
  for(int i=0;i<a;i++)cin>>ref[i];
  for(int j=0;j<b;j++)cin>>mic[j];
  int mini = 100000000;
  for(int i=0,x,y,c;i<m;i++){
    cin>>x>>y>>c;
  	mini=min(mini,ref[x-1]+mic[y-1]-c);
  }
  sort(ref.begin(),ref.end());
  sort(mic.begin(),mic.end());
  cout<<min(mini,ref[0]+mic[0]);
  
}