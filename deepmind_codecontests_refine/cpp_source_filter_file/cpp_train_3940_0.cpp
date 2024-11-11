#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  int a=1;
  cin >> N >> K;
  for (i=0;i<K;i++){
    a+=min(a,K);
  }
  cout << a << endl;
}
