#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  int count=0;
    vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
    count+=A[i];
  }
  int c=count;
  int a=0;
  for(int i=0;i<N;i++){
  cin>>A[i];
    a+=A[i];
    c=min(c,abs(a-(count-a)));
    
  
  }
cout<<c<<endl;
}
