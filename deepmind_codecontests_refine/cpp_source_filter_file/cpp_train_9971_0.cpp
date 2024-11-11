#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long int N,A[200200],B[200200];
  	cin>>N;
  	for(long long int i=0;i<N;i++){
     	cin>>A[i]>>B[i]; 
    }
  	sort(A,A+N);
    sort(B,B+N);
    if(N%2==1){
    	cout<<B[i/2]-A[i/2]+1<<endl; 
    }else{
        cout<<(B[i/2]+B[i/2-1])- (A[i/2]+A[i/2-1])+1<<endl;
    }
}
