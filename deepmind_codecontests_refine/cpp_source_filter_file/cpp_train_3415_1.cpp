// B
#include <iostream>
using namespace std;

int main(){
  int N,L;
  cin>>N>>L;
  int R = L+N-1

  int eat;
  if(L>0) eat=L;
  else if(R<0) eat=R;
  else eat=0;

  int answer = (R+L)*N/2 - eat;
  cout<<answer<<endl;
  return 0;
}