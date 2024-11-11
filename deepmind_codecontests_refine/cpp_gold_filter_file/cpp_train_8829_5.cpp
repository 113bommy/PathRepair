#include <bits/stdc++.h>
using namespace std;
int n,a[200000],b[200000];
long long r;
int main (){
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> a[i];
		b[i]=a[i]-i;
	}
	sort(b,b+n);
	for (int i=0;i<n;++i){
		r+=abs(b[i]-b[(n-1)/2]);
	}
	cout << r;
	return 0;
}