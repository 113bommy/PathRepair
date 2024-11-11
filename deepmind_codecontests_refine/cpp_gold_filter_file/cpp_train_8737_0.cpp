#include <bits/stdc++.h>

using namespace std;

int main(){
  int W,H,N;
  cin>>W;
  cin>>H;
  cin>>N;
  
  vector<int> row;
  for(int i = 0;i < N;++i){
    int a;
    cin>>a;
    row.push_back(a);
  }

  int o_s = W + H + W - 2;
  int o = W + H + W - 2;
  int i_s = W + H + W - 6;
  int c = 0;
  int ans = 0;

  for(int e : row){
    if(e == 0){
      --o_s;
    }
    else{
      --i_s;
    }

    if(o_s == 0 || i_s == 0){
      break;
    }
    else if(o - (W - 1) < o_s){
      if(o_s == i_s + 4){
        ++ans;
      }
    }
    else if(o - (W - 1) == o_s){
      continue;
    }
    else if(o - (W - 1) > o_s && o_s > o - (W + H - 2)){
      if(o_s == i_s + 2){
        ++ans;
      }
    }
    else if(o_s == o - (W + H - 2)){
      continue;
    }
    else if(o_s < o - (W + H - 2)){
      if(o_s == i_s){
        ++ans;
      }
    }
  }

  cout<<ans<<endl;

  return 0;
}
