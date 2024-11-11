//============================================================================
// Name        : AOJ.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int N;
	int D[100000];
	int R=0;
	cin>N;
	for(int i=0;i<N;i++){
		cin>>D[i];
	}
	int a1=1,a2=1,a3=1;
	for(int i=1;i<N;i++){
		if(D[i]==D[i-1]){
			R=max(R,a3);
			a3=a2+1;
			a2=a1+1;
			a1=1;
		}
		if(D[i]!=D[i-1]){
			a1+=1;
			a2+=1;
			a3+=1;
		}

	}
	R=max(R,a1);
	R=max(R,a2);
	R=max(R,a3);


	cout<<R<<endl;
	return 0;
}