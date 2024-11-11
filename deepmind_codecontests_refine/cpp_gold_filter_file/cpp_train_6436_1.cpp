#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

long long max(long long a,long long b){
	return (a>b)? a:b;
}
int j_k_bit_1or0(int j,int k){

}

int main (){
	long long NNN,MMM,maxx=0,p=0,sum=0;
	cin >> NNN >> MMM;
	long long a[3][NNN];
	rep(i,NNN){rep(j,3){scanf("%lld",&a[j][i]);}}
	vector <long long> temp[8];
	rep(i,8){
		rep(j,NNN){
			rep(k,3)(i & (1 << k))? p += a[k][j]:p -= a[k][j];
			temp[i].push_back(p);
			p=0;
		}
		sort(temp[i].rbegin(),temp[i].rend());
		sum=0;
		rep(k,MMM)sum += temp[i][k];
		maxx = max(sum,maxx);
	}
	printf("%lld",maxx);

	return 0;
}
