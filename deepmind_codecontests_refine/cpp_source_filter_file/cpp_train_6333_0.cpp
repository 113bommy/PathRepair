#include<bits/stdc++.h >
using namespace std;
long long ans,n,a[100001];
int main() {
	cin>>n;
	for(int i=0; i<n*2; i++) {
		cin>>a[i];
	}
	sort(a,a+n*2);
	for(int i=0; i<2*n; i++) {
		ans+=(i)*a[i];
	}
	printf("%.12lf\n",1.0*ans/(2*n-1));
	return 0;
}