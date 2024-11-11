#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;long long int x=0;
  vector<int>A
    (3*N);
  for(int i=0;i<3*N;i++)cin>>A.at(i);
  sort(A.begin(),A.end());
  for(int i=N;i<3*N;i+=2)x+=A.at(i);
  cout<<x<<endl;
}