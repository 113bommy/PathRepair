#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, r;
	scanf("%d", &N);
	
	int A[N];
	int B[N];
	for(r=0; r<N; r++){
		scanf("%d", &B[r]);
		A[r] = B[r];
	}
	
	sort( A, A+N );
	
	for(r=0; r<N; r++){
		if(B[r] == A[N-1]) printf("%d\n", A[N-2]);
		else printf("%d\n", A[N-1]);
	}
	
	
	return 0;
}