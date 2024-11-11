#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  cin>>A>>B;
  int count=0;
  for(int i=0;i<B-A+1){
    int k=i+A;
    if(k/10000==k%10&&k/1000%10==k%100/10) ++count;
  }
  cout<<count<<endl;
}