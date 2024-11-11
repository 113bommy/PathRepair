#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int L,R;

int main(){
	cin >> L >> R;
	if(R-L>=2019) puts("0");
	else {
		ll ans=0x3f3f3f3f;
		for(int i=L;i<=R;i++)
			for(int j=i+1;j<=R;j++)
			ans=min(ans,i*j%2019);
		cout<<ans;
	}
	return 0;
}