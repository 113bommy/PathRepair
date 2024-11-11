#include<bits/stdc++.h>

using namespace std;

int main(){
  int N,K;
  cin >> K >>N;
  vector<int> A(N);
  
  for(int i=0;i<N;i++)
    cin >> A.at(i);
  
  A.push_back(K+A.at(0));
  
  int l=0;
  for(int j=0;j<N;j++)
    l=max(l,A.at(j+1)-A.at(j));
  
  cout << K-l << endl;
}
  
