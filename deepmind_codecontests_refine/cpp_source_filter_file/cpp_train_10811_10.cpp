include <iostream>
using namespace std;
int main(){
	int n;cin>>n;
  	string s;cin s;
    int ret=0,ans=0;
   for(auto&& u:s){
   	if(u=='I')ret++;
     else (u=='D')ret--;
     ans=max(ans,ret);
   }
  cout<<ans<<endl;
}