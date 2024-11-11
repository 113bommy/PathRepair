#include<iostream>
using namespace std;
long long a[200100],b[200100],n,m,ans;
bool flag;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b[i]=i-a[i];
    	if(a[i]>=i||a[i]>a[i-1]+1){
    		flag=true;
		}
	} 
	if(flag){
		cout<<"-1";
		return 0;
	}
	for(int i=n;i>0;i--){
      if(i!=n&&b[i]==b[i+1])continue;
      ans+=a[i];
    }
    cout<<ans;
    return 0;
}