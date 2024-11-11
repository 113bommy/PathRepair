#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	vector<long long>a,b;
	cin>>n;
	a.resize(n);
	b.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i]-i-1;
	}
	sort(b.begin(),b.end());
	long long c=b[n/2],ans=0;
	for(int i=0;i<n;i++)ans+=abs(b[i]-c);
	cout<<ans<<endl;
	return 0;
}