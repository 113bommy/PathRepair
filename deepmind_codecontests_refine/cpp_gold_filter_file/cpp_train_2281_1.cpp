#include <iostream>
#include <algorithm>
using namespace std;

int main() {
int N,R,p,c;
while (cin>>N>>R&&N) { 
	int A[100]={};
	for(int i=0;i<N;i++){
		A[i]=i+1;
	}
	reverse(A,A+N);
	for (int i=0; i<R; ++i) {
	cin >> p >> c ;
	rotate(A,A+p-1,A+p+c-1);

 }
 cout << A[0] << endl;
 }
	return 0;
}