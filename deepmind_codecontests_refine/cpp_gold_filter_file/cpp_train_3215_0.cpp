#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
using vi = vector<int>;

string str;
string stra;
int id = 0;

vi number(){
  vi res;
  for (; isdigit(stra[id]); id++) {
    res.push_back(stra[id] - '0');
  }
  reverse(res.begin(),res.end());
  return res;
}
int solve(){
  stra = str;
  for (int i = 9; i >= 0; i--) {
    id = 0;
    for (int j = 0; j <(int)str.size(); j++) {
      if (str[j] == 'X') {
        stra[j] = i + '0';
      }
    }
    vi a = number();
    if (stra[id] == '+' ) {
      id++;
    }  
    vi b = number();
    a.resize(max(b.size() + 1,a.size()+1),0);
    for (size_t j = 0; j < b.size(); j++) {
      a[j] += b[j];
      if (a[j]>=10) {
        a[j] -= 10;
        a[j+1]++;
      }
    }
    for (size_t j = b.size(); j < a.size()-1; j++) {
      if (a[j] >= 10) {
        a[j] -= 10;
        a[j+1]++;
      }
    }
    if (stra[id] == '=') {
      id++;
    }
    b = number();

    if(a[a.size()-1]==0){
      a.pop_back();
    }
    if (a.size() != b.size()) {
      continue;
    }
    
    // if (a.size() >= b.size()) {
    //   b.resize(a.size(),0);
    // } else {
    //   a.resize(b.size(),0);
    // }
    int flag = 0;
    for (size_t j = 0; j < a.size(); j++) {
      if (a[j] == b[j]) {
        flag++;
      }
    }
    if (flag ==(int)a.size()) {
      return i;
    } 
    
  }
  return -1;
}
int main(){
  cin >> str;
  while(str.size()){
  int ans = solve();
  if (ans >= 0) {
    cout << ans << endl;
  } else {
    puts("NA");
  }
  str.clear();
  cin >> str;
}
  return 0;
}

