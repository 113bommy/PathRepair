#include<iostream>
using namespace std;

int main(){
 int E, Y;
 cin >> E >> Y;

 switch(E){
  case 0:
   if(1868<=Y&&Y<=1911) cout << 'M' << Y-1867 << endl;
   if(1912<=Y&&Y<=1925) cout << 'T' << Y-1911 << endl;
   if(1926<=Y&&Y<=1988) cout << 'S' << Y-1925 << endl;
   if(1989<=Y&&Y<=2016) cout << 'H' << Y-1988 << endl;
   break;
  case 1:
   cout << 1867 + Y << endl;
   break;
  case 2:
   cout << 1911 + Y << endl;
   break;
  case 3:
   cout << 1925 + Y << endl;
   break;
  case 4:
   cout << 1988 + Y << endl;
   break;
 }

 return 0;
}
~                                    