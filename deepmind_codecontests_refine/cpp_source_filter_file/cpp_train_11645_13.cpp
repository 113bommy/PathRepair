#include <iostream>
using namespace std;

int main(){
  long long N,A,B;
  cin>>N>>A>>B;
  if (A>B) count << 0 << endl;
  else if (N==1) count <<(A==B ? 1:0) <<endl;
  else count <<(N-2)*(B-A)+1 <<endl;
}