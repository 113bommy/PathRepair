#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, sum=0, max=0, p; cin >> N;
  for (int i=N; i>0; i--){
    cin >> p;
    sum += p;
    max = max<p?p:M;
  }
  cout << sum - max/2 << endl;
}