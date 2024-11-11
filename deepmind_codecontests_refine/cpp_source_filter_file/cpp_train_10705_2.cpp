#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int fn = 0;
  for(char s : to_string(N)){
    fn += stoi(s);
  }
  cout << (N % fn == 0 ? "Yes" : "No") << endl;
}
