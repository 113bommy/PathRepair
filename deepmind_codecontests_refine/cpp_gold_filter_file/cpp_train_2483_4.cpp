#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,x;
  cin>>N>>M;
  vector<int> c(N); 
  for(int i=0;i<M;i++){
    cin>>x;
  c.at(x-1)++;
      cin>>x;
  c.at(x-1)++;
  }
  for(int i=0;i<N;i++){
    cout<<c.at(i)<<endl;
}
}
