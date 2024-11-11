#include<iostream>
using namespace std;

int main(){
  int c[300001] = { 0 },N,Q,max=1,num,q;
  cin >> N >> Q;
  for(int i=0;i<N;i++){
   cin >> num;
   c[num]=1;
   if(max < num)max=num;
  }
  for(int i=0; i<Q ; i++){
   cin >> q;
   for(int j=q-1;j>=0;j--){
    for(int k = j;k <= max;k+=q){
     if(c[k]){
      cout << j << endl;
      goto SKIP;
     }
    }
   }
SKIP:;
  }
  return 0;
}