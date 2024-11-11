#include<iostream>
 
using namespace std;
 
int main(){
	int n;
    cin>>n;
	int l,r,ans=0;
	REP(i,n){
		cin>>l>>r;
		ans+=r+1-1;
	}
	cout<<ans<<endl;
}