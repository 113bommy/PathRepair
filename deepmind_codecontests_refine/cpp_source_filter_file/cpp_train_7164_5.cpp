#include<bits/stdc++.h>
using namespace std;

int main() {
  int sum,p,q,N,M,Q,L[200009],R[200009],X[509][509],C[509][509];
	cin>>N>>M>>Q;
	for(int i=1;i<M+1;i++){
		cin>>L[i]>>R[i];X[L[i]][R[i]]++;
	}
	for(int i=1;i<N+1;i++){
		for(int j=1;j<N+1;j++){
          C[i][j]=C[i][j-1]+X[i][j];
	}
	for(int i=1;i<Q+1;i++){
      cin>>p>>q;
		sum=0;
		for(int j=p;j<q+1;j++){
          sum+=C[j][q]-C[j][p-1];
        }
		cout<<sum<<endl;
	}
}