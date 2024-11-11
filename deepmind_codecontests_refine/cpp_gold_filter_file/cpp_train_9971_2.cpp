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
    	cout<<B[N/2]-A[N/2]+1<<endl; 
    }else{
        cout<<(B[N/2]+B[N/2-1])- (A[N/2]+A[N/2-1])+1<<endl;
    }
}
