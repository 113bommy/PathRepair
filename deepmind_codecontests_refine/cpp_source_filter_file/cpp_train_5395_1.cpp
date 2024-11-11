#include <bits/stdC++.h>
using namespace std;
int main(void){
  int N;
  cin >> N;
  int list[5]={135,187,165,105,195};
  sort(list,list+5);
  int i;
  for(i=0;i<5;i++){
    if(N<list[i]) break;
  }
  cout<<i;
}
