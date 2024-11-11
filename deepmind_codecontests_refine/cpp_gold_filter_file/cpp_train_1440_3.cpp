#include<iostream>
using namespace std;
int main(){
  int tmp, min=1e5, N, X;cin>>N>>X;
  int m[N];for(int i=0;i<N;i++){cin>>tmp;X-=tmp;if(min>tmp)min=tmp;}
  cout<<N+int(X/min)<<endl;
}
