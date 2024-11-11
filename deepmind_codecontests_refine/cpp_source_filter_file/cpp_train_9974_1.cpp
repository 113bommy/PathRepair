#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> s(n);
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }
  sort(s.begin(),s.end());
  for(int i = s[1]; i > 0; i--){
    int x = 0;
    for(int j = 0; j < n; j++){
      if(s[j]%i != 0){
        x++;
      }
    }
    if(x == 1 || x == 0;){
      cout << s[i] << endl;
      break;
    }
  }
}