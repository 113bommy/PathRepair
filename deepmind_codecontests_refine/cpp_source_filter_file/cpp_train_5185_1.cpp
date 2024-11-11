#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,D,p=0;
  cin>>N>>D;
  vector<vector<int>> X(N,vector<int>(D));
  for(vector<int> &i:X)
    for(int &j;X)
      cin>>j;
  for(int i=0;i<N-1;i++){
    for(int j=i+1;j<N;j++){
      int l=0;
      for(int k=0;k<D;k++)
        l+=pow(X[i][k]-X[j][k],2);
      if(pow(l,0.5)==(int)pow(l,0.5))
        p++;
    }
  }
  cout<<p<<endl;
}