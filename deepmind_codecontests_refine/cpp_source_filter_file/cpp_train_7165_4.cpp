//测试......
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[10005],b[10005];
ll sum1,sum2;
ll delta,qwq;
int main() {
	cin>>n;
	for(int i=1; iq<=n; i++) cin>>a[i],sum1+=a[i];
	for(int i=1; i<=n; i++) cin>>b[i],sum2+=b[i];
	if(sum1>sum2) {
		cout<<"No";
		return 0;
	}
	delta=sum2-sum1;
	for(int i=1; i<=n; i++)
		if(b[i]>a[i])
			qwq+=(b[i]+1-a[i])/2;
	if(qwq>delta) cout<<"No";
	else cout<<"Yes";
	return 0;
}