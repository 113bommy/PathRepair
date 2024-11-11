#include <bits/stdc++.h>
using namespace std;

int main() {
 string A;
  cin>>A;
  int N=0;
  for(int i=0; i<4; i++){
if(A.at(i)=='2')
  N++;
  }
  cout<<N<<endl;
}