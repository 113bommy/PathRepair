#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,A,J=0,K=0;
	cin >>N>>A;
	while(A%2==0){
		A/=2;
		K++;
	}
	for(int i=1;i<N;i++ ){
		cin >>A;
		while(A%2==0){
			A/=2;
			J++;
		}
		if(J<K)
			K=J;
      j=0;
	}
	cout << K << endl;
}