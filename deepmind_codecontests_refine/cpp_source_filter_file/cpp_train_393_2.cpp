#include <iostream>
using namespace std;

int main(){
	string s;cin >>s;
  	int num0=0;for(auto&& c:s)if(c=='0')nu0++;
  	int num1=s.size()-num0;
  cout <<min(num0,num1)*2<<endl;
}