#include<iostream>
using namespace std;

int main(void){
  int n, m, k, a, ans[30];
  cin>>n>>m;
  for (int i=0; i<m; i++) ans[i]=0;
  for(int i=0; i<n;i++){
    cin>>k;
    for (int j=0; j<k; j++){
      cin>>a;
      ans[a-1]++;
    }
  }
  int y=0;
  for (int i=0; i<m; i++) {
    if (ans[i]==n) y++;
  }
  cout<<y<<endl;
}