#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef stringstream ss;
template<class T> inline string toStr(T f){ ss sss; sss << f; return sss.str(); }

int main(){
  
  int n;
  while(cin >> n, n){
    string now, prev; cin >> prev;
    
    for(int i = 0; i < n; i++){
      int cnt;
      for(int j = 0; j < prev.size(); j+=cnt){
	cnt = 0;
	for(int k = j; prev[k] == prev[j]; k++, cnt++);
	now.append(toStr(cnt));
	now.append(1, prev[j]);
      }
      prev = now;
      now = "";
    }
     
    cout << prev << endl;
  }