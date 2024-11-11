#include <iostream>
using namespace std;
int W,a,b;

int main(){
  cin W >> a >> b;
  if(a>b) swap(a,b);
  cout << min(b-(a+W),0) << endl;
}