#include <bits/stdc++.h>
using namespace std;

int main() {
 int N;
  cin >> N;
  vector<tuple<string,int,int>> a(N);
  for (int i; i<N; i++){
   string S;
    int P;
    cin >> S >> P;
    P=P*(-1);
    v[i]=make_tuple(S,P,i);
  }
  sort (v.begin(),v.end());
  for(int b : v){
   cout << get<2>(b)+1 << endl; 
  }
}
