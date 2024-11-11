#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main(){
  int N;cin>>N;
  int k=0;
  for (int i=1;i*i<=N;++i){
    if((i(i-1))/2==N){k=i;break;}
  }
  if(k==0){cout << "No"<< endl;}
  else{
    cout << "Yes" << endl;
    cout << k << endl;

    vi ans[k+1];
    int count=0:
    for (int i=1;i<k;++i){
      for (int j=i+1;j<=k;++j){
        count++;
        ans[i].push_back(count);
        ans[j].push_back(count);
      }
    }

    for (int i=1;i<=k;++i){
      cout << k-1 << ' ';
      for (int j=0;j<k-1;++j){
        cout << ans[i][j] << ' ';
      }
      cout << endl;
    }
  }

  return 0;
}