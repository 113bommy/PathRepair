#include<iostream>
using namespace std;

int main(){
  int t,n,s,f,cnt;
  while(true){
    cin>> t;
    cnt = 0;
    if(t==0)break;
    cin >> n;
    for(int i=0;i<n;i++){
      cin >> s >> f;
      cnt+= f-s;
    }
    if(cnt >= t)cout<< "OK" << endl;
    else cout << t-cnt << endl;

  }
  return 0;
}