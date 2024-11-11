#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n;
  cin >> n;
  int a;
  set<int> st;
  int cnt = 0;
  for(int i=0;i<n;i++){
    cin >> a;
    if(a >= 3200){
      cnt++;
    }else{
      st.insert(a / 400);
    }
  }
  cout << max(1,st.size()) << " " << st.size() + cnt << endl;
  return 0;
}