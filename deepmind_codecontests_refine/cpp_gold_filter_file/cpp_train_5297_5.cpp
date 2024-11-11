#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n,time[10000];
	long long ans=0;
	
	while(cin>>n){
		if(n==0)break;
		int wait=0;
		for(int i=0;i<n;i++)cin>>time[i];
		sort(time,time+n);
		for(int i=0;i<n;i++){
			ans+=wait;
			wait+=time[i];
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}