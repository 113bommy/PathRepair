#include<iostream>
using namespace std;
int N;
int main(){
  cin>>N;
  cout<<N%1000%111&&N/10%111?"No":"Yes"<<endl;
  return 0;
}
