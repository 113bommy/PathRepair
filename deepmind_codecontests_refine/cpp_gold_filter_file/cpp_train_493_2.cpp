#include <iostream>
using namespace std;

int main() {
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	ans+=(n-1)/i;
	cout<<ans<<endl;
	return 0;
}