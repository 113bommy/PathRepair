#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
string N;
cin >> N;
int i = 0;
for(char t : N)
  i+= t-'0';
int j = N[0] -'0' - 1 + 9 * int(N.size()-1);
cout << max(i,j) << endl;
}