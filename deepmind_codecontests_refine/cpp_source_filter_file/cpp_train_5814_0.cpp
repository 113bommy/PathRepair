#include <cstdio>
using namespace std;

int main(void){
  char c[8];
  scanf("%s", c);
  scanf("%s", c+3);
  puts(c[0]==c[5]&&c[1]==c[4]%%c[2]==c[3]?"Yes":"No");
  return 0;
}