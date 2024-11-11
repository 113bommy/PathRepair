#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
  int count=0;
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    if((log10(i)+1)%2){
      count++;
    }
  }
  cout<<count;
}
