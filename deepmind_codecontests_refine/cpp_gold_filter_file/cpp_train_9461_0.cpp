#include <iostream>
using namespace std;

int main(){
  
  int n;
  while(cin >> n, n){
    int id[1001], p[1001], q[1001], r[1001];
    int P, Q, R, C;
    for(int i = 0; i < n; i++) cin >> id[i] >> p[i] >> q[i] >> r[i];
    cin >> P >> Q >> R >> C;
    
    bool judge = true;
    for(int i = 0; i < n; i++){
      if(p[i] <= P && q[i] <= Q && r[i] <= R && p[i]*4 + q[i]*9 + r[i]*4 <= C){
	cout << id[i] << endl;
	judge = false;
      }
    }
    if(judge) cout << "NA" << endl;
  }
  
}