#include <bits/stdc++.h>
using namespace std;

int main() {

  int N,K,x,n=0;
  cin >> N >> K;
  for(int i=0;K>i;i++){
    cin >> x;
    if(x<K/2) n+=x*2;
    else n+=(K-x)*2
  }
  cout << n << endl;
}