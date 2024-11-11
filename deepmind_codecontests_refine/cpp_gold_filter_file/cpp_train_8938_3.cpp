#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int size = 3;

bool check ( char hyo[size][size], char mark )
{
  for (int y = 0; y < size; ++y)
    for (int x = 0; x < size; ++x)
    {
       if (x+2 < size && hyo[y][x] == mark && hyo[y][x+1] == mark && hyo[y][x+2] == mark) { return true; }
       if (y+2 < size && hyo[y][x] == mark && hyo[y+1][x] == mark && hyo[y+2][x] == mark) { return true; }
       if (x+2 < size && y+2 < size && hyo[y][x] == mark && hyo[y+1][x+1] == mark && hyo[y+2][x+2] == mark) { return true; }
       if (x-2 >= 0 && y+2 < size && hyo[y][x] == mark && hyo[y+1][x-1] == mark && hyo[y+2][x-2] == mark) { return true; }
    }
    return false;
}

int main ( void )
{
  string str;
  while (cin >> str)
  {
     char hyo[size][size];

     for (int y = 0; y < size; ++y)
       for (int x = 0; x < size; ++x)
         hyo[y][x] = str[y*size + x];

     char judge = 'd';
     char mark[] = { 'o', 'x' };

     for (int i = 0; i < 2; ++i)
     {
        if (check(hyo, mark[i])) { judge = mark[i]; }
     }

     cout << judge << endl;
  }
  return 0;
}