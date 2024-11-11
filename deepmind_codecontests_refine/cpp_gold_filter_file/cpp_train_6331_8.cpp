#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
  int N,P,M=0,sum=0;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> P;
  	M=max(M,P);
    sum+=P;
  }
  cout << sum-M/2 << endl;
  return 0;
}