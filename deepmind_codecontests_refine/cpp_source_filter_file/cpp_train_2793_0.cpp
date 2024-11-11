#include<bits/stdc++.h>
using namespace std;

int a[100001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	a[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	long long int L=2,R=2;
	if(2%a[k]!=0){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=n;i>=1;i--){
		R+=a[i]-1;
		L=(L%a[i-1]==0?L:((L/a[i-1]+1)*a[i-1]));
		R=R/a[i-1]*a[i-1];
		if(L>R){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<L<<' '<<R<<endl;
}
