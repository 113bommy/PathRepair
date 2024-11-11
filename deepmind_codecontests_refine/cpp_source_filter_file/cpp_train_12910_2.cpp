#include <iostream>
using namespace std;
#define MAX 100000
typedef long long llong;

int n,k;
llong T[MAX];

int check(long p){
	int i =0;
	for (int j=0;j<k;j++){
		llong s=0;
		while(s+T[i]<=p){
			s +=T[i];
			i++;
			if (i==n) return n;
		}
	}
	return i;
}


int solve(){
	llong left =0;
	llong right = 100000 * 10000;
	llong mid;
	while(right - left >1 ){
		mid =(left+right)/2;
		int v=check(mid);
		if(v>=n)right=mid;
		else left=mid;
	}
	return right;
}


main(){
	cin() >> n >> k;
	for (int i =0; i<n;i++){
	cin >> T[i];
	}
	llong ans=solve();
	cout << ans << endl;
}