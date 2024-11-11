#include <iostream>
using namespace std;

int main() {
  
  char b, c[128];
  c['A'] = 'T';
  c['T'] = 'A';  
  c['C'] = 'G';  
  c['G'] = 'C';
    cin >> b;
    cout << c[(int)b] << endl;
    
}
