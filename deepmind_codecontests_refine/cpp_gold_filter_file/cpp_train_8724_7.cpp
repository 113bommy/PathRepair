#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin>>N>>M;
  vector<int>v(M);
  for(int X=0;X<N;X++){
    int K;
    cin>>K;
    for(int Y=0;Y<K;Y++){
      int H;
      cin>>H;
      v[H-1]++;
    }
  }
  int G=0;
  for(int X=0;X<M;X++){
    if(v[X]==N){
      G++;
    }
  }
  cout<<G<<endl;
}