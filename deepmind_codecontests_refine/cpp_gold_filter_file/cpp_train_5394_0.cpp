#include<iostream>
using namespace std;

int main (){
  int N;
  cin >> N;
  int s = 0,m = 0;
  for (int i = 0; i < N; ++i){
    int L;
    cin >> L;
    m =max(m,L);
    s += L;
  }
  if (m < s-m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
  