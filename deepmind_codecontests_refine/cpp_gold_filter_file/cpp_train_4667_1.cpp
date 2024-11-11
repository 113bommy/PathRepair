#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;

int main(){
  int H,W;
  cin >> H>>W;
  
  vector<string> A(H);
  rep(i,0,H) cin >>A[i];
  
  vector<bool> row(H, false);
  vector<bool> col(W, false);
  
  rep(i,0,H){
    rep(j,0,W){
      if(A[i][j]=='#'){
        row[i] = true;
        col[j] = true;
      }
    }
  }

  rep(i,0,H){
    if(row[i]){
      rep(j,0,W){
        if (col[j]) cout << A[i][j];
       }
      cout << endl;
    }
  }
}