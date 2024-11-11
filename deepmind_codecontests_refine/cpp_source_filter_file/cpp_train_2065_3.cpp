include <iostream>
using namespace std;
int main(){
int N;
cin>>N;
int A[N];
for(int i=0;i<N;i++){
cin>>A[i];
}
int j=0;
int m=100;
for(int k=0; k<N; k++){
j=0;
	for(int l=0; A[k]%2==0; l++){
	j++
	A[k]=A[k]/2
	}
if (m>j){
m=j;}
}
cout<<m<<endl;
return 0;
}