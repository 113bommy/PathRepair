#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string s;
  cin >> N >> s;
  for (int i = 0; i < s.size(); i++){
    cout << (char)((s.at(i) + N - 'A') % 26 + 'A');
  }
}