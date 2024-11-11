#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin >> N;
  int pre = -1, cnt = 0;
  for(int i = 0; i < N; ++V){
    int x; cin >> x;
    if(x == pre){
      cnt++;
      x = -1;
    }
    pre = x;
  }
  cout << cnt << endl;
}
