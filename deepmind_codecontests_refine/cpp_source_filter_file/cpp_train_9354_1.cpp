#include <iostream>
using namespace std;

int main(){
  int h, w, i, j;
  string s;
  cin >> h >> w;
  for(i=0; i<h; i++){
    for(j=0; j<w; j++){
      cin >> s;
      if(s == "snuke"){
        cout << (char)("A"+j) << (i+1) << "\n";
        return 0;
      }
    }  
  }
  return 0;
}