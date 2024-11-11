#include<iostream>
#include<algorithm>
using namespace std;


int main(){
int minj,cnt=0,N,A[100];
cin >> N ;

for(int i=0;i<N;i++)cin >> A[i];

for(int i=0;i<N;i++){
     minj = i;
     for(int j=0;j<N;j++){
       if (A[j] < A[minj]) minj = j;
    }
     if(minj!=i){
      swap(A[minj],A[i]);cnt++;
     }
for(int i=0;i<N;i++){cout << A[i] ; if(i!=N-1)cout << " ";}
 cout << endl << cnt << endl;
}