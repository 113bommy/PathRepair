#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int64_t b = 1;
  for (int i=0; i<N; i++){
    int64_t a;
    cin >> a;
    if (b != -1){
      int64_t c=1000000000000000000/b;
      if (a>c)
        b = -1;
      else
        b *= a;
    }
    else if (a == 0){
      b = 0;
      break;
    }
  }
  
  cout << b << endl;

}