#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
  int count=0;
  int N;
  cin>>N;
  for(int i=1;i<N+1;i++){
    if((int(log10(i))+1)%2){
      count++;
    }
  }
  cout<<count;
}
