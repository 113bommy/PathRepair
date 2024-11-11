#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n , a , b ;
	cin>>n>>a>>b;
	int arr[n];
	for(int i = 0 ; i < n ; ++i)cin>>arr[i];
	ll res = 0;
	for(int i = 0 ; i < n-1 ; ++i){
		ll dis = abs(arr[i] - arr[i+1]);
		res += min(dis*a , b);
	}
	cout<<res;
	return 0;
}