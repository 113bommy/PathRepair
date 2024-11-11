#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
 
  if(N % 1000 % 111 && N / 10 % 111)
    cout << "No";
  else
    cout << "Yes";
 
}