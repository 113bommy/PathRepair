#include <iostream>
using namespace std;

int N;
int A[20010].B[20010];

int main(){
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> A[i];
		B[A[i]] = i;
	}
	for(int i=1;i<=N;i++){
		if(i!=N) cout << 30000*i << " ";
		else cout << 30000*i << endl;
	}
	for(int i=1;i<=N;i++){
		if(i!=N) cout << 30000*(N-i) + B[i] <<" ";
		else cout << 30000*(N-i) + B[i] << endl;
	}
}