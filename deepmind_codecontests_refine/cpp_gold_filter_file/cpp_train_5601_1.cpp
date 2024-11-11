#include<bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin>>N;
  double A[N] ,sum=0;
  for(int i=0;i<N;i++) {
    cin>>A[i];
    sum+=1/A[i];
  }
  cout<<1/sum<<endl;
  return 0;
}
