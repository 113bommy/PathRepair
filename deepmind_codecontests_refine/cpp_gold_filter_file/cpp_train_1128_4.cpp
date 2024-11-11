#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  set<int> st;
  int cnt = 0;
  int a;
  for ( int i = 0; i < n; i++){
    cin >> a;
    if ( a/400 >= 8){
      cnt ++;
    } else {
      st.insert(a/400);
    }
  }

  cout << max((int)st.size(), 1) << " " << st.size() + cnt << endl;

  return 0;
}