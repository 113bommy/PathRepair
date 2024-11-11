#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  string S;
  cin >> N >> S;
  int count, ans = 0;
  string C;
  for(int i = 0; i < 1000; i++){
    C = to_string(i);
    if(C.size() == 1)C = "0" + C;
    if(C.size() == 2)C = "0" + C;
    count = 0;
    for(int j = 0; j < N; j++){
      if(C.at(count) == S.at(j))count++;
      if(count == 3){
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
