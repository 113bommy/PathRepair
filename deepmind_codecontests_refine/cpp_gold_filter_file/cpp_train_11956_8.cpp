#include <bits/stdc++.h>
using namespace std;

int main() {

  int N,K,x,n=0;
  cin >> N >> K;
  for(int i=0;N>i;i++){
    cin >> x;
    if(x*2<K) n+=x*2;
    else n+=(K-x)*2;
  }
  cout << n << endl;
}