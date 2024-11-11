#include <bits/stdc++.h>
using namespace std;

int main(){
int h,w;cin>>h>>w;
vector<string>s(2*h);
for(int i=0;i<h;i++){
	string x;cin>>x;
 s[2*i]=x;s[2*i+1]=x;
}
for(auto&& u:s)cout<<u<<endl;
}