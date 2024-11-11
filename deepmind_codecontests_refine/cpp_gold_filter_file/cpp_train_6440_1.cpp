#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, hito, kokugai;
  string S;
  cin >> N >> A >> B >> S;
  hito =0; kokugai =0;
  
  for(int i= 0; i<N; i++){
    if(S.at(i)=='a' && hito < A+B){
      cout << "Yes" << endl;
      hito ++;
    }
    else if(S.at(i)=='b' && hito < A+B && kokugai <B){
      cout << "Yes" << endl;
      hito ++;
      kokugai ++;
    }
    
    else cout << "No" << endl;
  }
}
