#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int bits = 0;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin>>A[i];
    bits ^= A[i];
  }
  for(int i=0;i<n;i++){
    cout<<(A[i]^bits)<<" ";
  }
  cout<<endl;
}
