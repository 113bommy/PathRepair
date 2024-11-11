#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int sum=0;
  for(int i=1;i<N+1;i++){
  if(i%3!=0&&i%5!=0)sum++;
  }

      cout<<sum<<end;
 return 0;
}