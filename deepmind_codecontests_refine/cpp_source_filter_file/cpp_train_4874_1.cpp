#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
int main(){
  int N
  ll B;
  cin>>N;
  vector<ll> A(N);
  for(int i = 0;i<N;i++){
  	cin>>A[i];
  }for(int i = 0;i<N;i++){
  	cin>>B;
  	A[i]-=B;
  }
  sort(A.begin(),A.end());
  cout<<A[0]<<endl;
  cout<<A[1]<<endl;
  ll sum = 0;
  int minus = 0;
  while(minus<N&&A[minus]<0){
  	sum -= A[minus];
  	minus++;
  }
  int i = N-1;
  while(i>=0&&A[i]>0&&sum>0){
  	sum -= A[i];
  	i--;
  }
  if(sum>0){
  	cout<<-1<<endl;
  }else{
  	cout<<minus+(N-1)-i<<endl;
  }

  return 0;
}
