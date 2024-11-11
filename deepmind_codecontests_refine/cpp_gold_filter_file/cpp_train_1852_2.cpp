#include <bits/stdc++.h>
using namespace std;
int N,X,Y;
int cnt[2020];

int main(){
  cin>>N>>X>>Y;
  for(int i=1; i<=N-1; i++){
    for(int j=i+1; j<=N; j++){
      cnt[min(j-i,abs(X-i)+1+abs(Y-j))]++;
    }
  }
  for(int k=1;k<N;k++)cout<<cnt[k]<<endl;
}
