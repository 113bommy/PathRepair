#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int a;
  set<int> D={};
  for (int i=0;i<N;i++){
    cin >> a;
    D.incert(a);
  }
  cout << D.size() << endl;
 }
