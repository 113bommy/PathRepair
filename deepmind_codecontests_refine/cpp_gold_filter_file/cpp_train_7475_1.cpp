#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,Q;
  int sum=0;
  string S;
  cin >> N >> Q >> S;
  vector<int> a(S.length(),0);
  for(int i=0;i<S.length();i++){
    if(S[i]=='A' && S[i+1]=='C'){
      sum+=1;
    }
    a[i+1]=sum;
  }
  for(int i=0;i<Q;i++){
    int l,r;
    cin >> l >>r;
    cout << a[r-1]-a[l-1] << endl;
  }
}