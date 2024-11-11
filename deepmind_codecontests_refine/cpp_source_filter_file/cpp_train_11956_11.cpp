#include <bits/stdc++.h>
using namespace std;

  int main(){
    string N,K;
    cin >> N >> K;
    int x,s=0;
    for (int i=0;i<N;i++){
      cin >> x;
      s+=2*min(x,K-x);
    }
    cout << s << endl;
  }
