#include <bits/stdc++.h>
using namespace std;
int main() {
  int rows, columns;
  long queriesNo;
  char query;
  int firstIndex, secondIndex;
  int temp;
  scanf("%d %d %d", &rows, &columns, &queriesNo);
  long matrix[1001][1001];
  int rowsV[1001];
  int columnsV[1001];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  for (int i = 0; i < 1001; i++) {
    rowsV[i] = i;
    columnsV[i] = i;
  }
  for (int k = 0; k < queriesNo; k++) {
    scanf("%d %d %d", &query, &firstIndex, &secondIndex);
    if (query == 'r') {
      swap(rowsV[firstIndex - 1], rowsV[secondIndex - 1]);
    } else if (query == 'c') {
      swap(columnsV[firstIndex - 1], columnsV[secondIndex - 1]);
    } else if (query == 'g') {
      printf("%d\n", matrix[rowsV[firstIndex - 1]][columnsV[secondIndex - 1]]);
    }
  }
  return 0;
}
