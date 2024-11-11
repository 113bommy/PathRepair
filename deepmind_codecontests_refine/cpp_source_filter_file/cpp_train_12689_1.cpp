#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxi(int x,int y){
  if(y==0 || x==y) return x;
  else if(x==1 || y==1) return 1;
  else if(x>y) return maxi(y,x%y);
  else return maxi(x,y%x);
}

int pow(int x) return x*x;

int main(){
  int w,h,c;
  cin >> w >> h >> c;

  cout << (w*h/pow(maxi(w,h)))*c << endl
    
  return 0;
}

