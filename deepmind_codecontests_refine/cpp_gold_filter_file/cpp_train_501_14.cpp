#include<iostream>
#include<vector>
 
using namespace std;
 
int main(){
int n;cin>>n;
int up=0, low=1001;
for(int i=0;i<n;i++){
int t;cin>>t;
up=max(up,t);
low=min(low,t);
}
cout<<up-low<<endl;
return 0;
}