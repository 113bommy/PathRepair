#include <bits/stdc++.h>
using namespace std;
#define N 100000
int main() {
	int n;
	long long int k;
	cin>>n>>k;
	long long int hoge[N]={};
	int a,b;
	for(int i=0;i<n;i++){
		
		cin>>a>>b;
		hoge[a-1]+=b;
	}
 	for(int i=0;i<N;i++){
 		k=k-a[i]
 		if(k<=0){
 			cout<<i+1<<endl;
 			break;
 		}
 	}
	return 0;
}