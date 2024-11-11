#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N;
    scanf("%d",&N);
    ll A[N],C=0,D=0;
    for(int i=0;i<N;i++){
		scanf("%lld",&A[i]);
	}
	sort(A,A+N);
	int K=N/2;
	
	A[N/2];
	if(N%2){
		if( (A[K]-A[K-1]) > (A[K+1]-A[K]) ){
			//D bigger\
			for(int i=0;i<K;i++){
				C+=A[i];
			}
			for(int i=K;i<N;i++){
				D+=A[i];
			}
			printf("%lld",2*D-2*C-A[K+1]-A[K]);
		}else{
			//C bigger
			for(int i=0;i<K+1;i++){
				C+=A[i];
			}
			for(int i=K+1;i<N;i++){
				D+=A[i];
			}
			printf("%lld",2*D-2*C+A[K-1]+A[K]);
		}
	}else{
		for(int i=0;i<K;i++){
			C+=A[i];
		}
		for(int i=K;i<N;i++){
			D+=A[i];
		}
		printf("%lld",2*D-2*C-A[K]+A[K-1]);
	}
}
	
