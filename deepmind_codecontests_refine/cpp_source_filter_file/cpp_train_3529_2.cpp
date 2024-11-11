//============================================================================
// Name        : AOJ.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
long long P[100001];
long long A[100001],B[100001],D[100001];
int D[100001];
int main() {
	int N,M;
	long long R=0;

	cin>>N>>M;
	for(int i=1;i<M+1;i++)cin>>P[i];

	for(int i=1;i<N;i++)cin>>A[i]>>B[i]>>C[i];

	for(int i=1;i<M;i++){
		if(P[i]<P[i+1]){
			for(int j=P[i];j<P[i+1];j++)D[j]+=1;
		}else{
			for(int j=P[i+1];j<P[i];j++)D[j]+=1;
		}
	}

	for(int j=1;j<N;j++)R+=min(D[j]*A[j],D[j]*B[j]+C[j]);

	cout<<R<<endl;
	return 0;
}