#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int fn = 0;
  for(char s : to_string(N)){
    fn += s - '0';
  }
  cout << (N % fn == 0 ? "Yes" : "No") << endl;
}
