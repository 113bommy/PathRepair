#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  while(cin >> n >> m, n){
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    for(int i=0;i<m;i++){
      cin >> b[i];
    }

    int step = 0, cur = 0;
    for(;;){
      cur += b[step];
      cur += a[cur];
      step++;
      if(cur >= n-1)break;
    }
    cout << step << endl;
  }
}