#include <iostream>
#include <set>
using namespace std;

int main(){
  set<int> s;
  for(int i = 0, t; i < 3; i++)
    cin >> t; s.insert(t);
  cout << s.size() << endl;
  return 0;
}
