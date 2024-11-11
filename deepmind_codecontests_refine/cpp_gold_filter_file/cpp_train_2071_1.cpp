#include <iostream>
using namespace std;

int main(){
  int a,b,n;
  cin >> a >> b >> n;

  bool flg=0;
  for(int i=0; i<n; i++){
    int s,f;
    cin >> s >> f;

    if(f<=a || b<=s){
      continue;
    }else{
      flg=1;
    }
  }

  cout << flg << endl;

  return 0;
}

