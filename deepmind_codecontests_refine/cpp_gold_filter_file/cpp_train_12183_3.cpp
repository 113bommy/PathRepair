#include <cmath>
#include <iostream>
using namespace std;

int V, E, R, S[500010], T[500010], D[500010];
int C[100010];
const int Inf = 10000*100000+100;

int main(){
 cin >> V >> E >> R;
 for(int i=0; i<E; i++){
  cin >> S[i] >> T[i] >> D[i];
 }
 for(int j=0; j<V; j++){
  C[j]=Inf;
 }
 C[R]=0;
 for(int t=0; t<V; t++){
  bool update = false;
  for(int i=0; i<E; i++){
   int s = S[i], t = T[i], d = D[i];
   if(C[s]<Inf && (C[s]+d)<C[t]){
    C[t] = C[s]+d;
    update = true;
   }
  }
  if(!update)break;
 }
 
 for(int m=0; m<V; m++){
  if(C[m]==Inf){
   cout << "INF" << endl;
  }
  else{
   cout << C[m] << endl;
  }
 }
}