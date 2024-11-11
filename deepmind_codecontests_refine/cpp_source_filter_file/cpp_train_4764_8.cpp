#include <bits/stdc++.h>
using std::endl;
using std::make_pair;
using std::pair;
using std::vector;
namespace {
struct RC {
  int row, col;
  inline RC() {}
  inline RC(int r, int c) : row(r), col(c) {}
  inline bool operator==(const RC& o) { return (row == o.row && col == o.col); }
};
}  // namespace
namespace {
const int MaxCol = 50;
}
namespace {
inline int& at(int fld[1 + 4][1 + MaxCol], const RC& pt) {
  return fld[pt.row][pt.col];
}
}  // namespace
int main(void) {
  using std::cin;
  using std::cout;
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  static int fld[1 + 4][1 + MaxCol];
  for (int irow = 1; irow <= 4; ++irow) {
    for (int icol = 1; icol <= N; ++icol) {
      int num;
      cin >> num;
      fld[irow][icol] = num;
    }
  }
  int unparkedCnt = K;
  RC freeCell(-1, -1);
  vector<pair<int, RC> > moves;
  for (int pass = 0; pass < 2 * K; ++pass) {
    for (int irow = 2; irow <= 3; ++irow) {
      const int ipark = (irow == 2 ? 1 : 4);
      for (int icol = 1; icol <= N; ++icol) {
        if (fld[irow][icol] == 0) {
          freeCell = RC(irow, icol);
          continue;
        }
        if (fld[irow][icol] == fld[ipark][icol]) {
          moves.push_back(make_pair(fld[irow][icol], RC(ipark, icol)));
          fld[irow][icol] = 0;
          freeCell = RC(irow, icol);
          --unparkedCnt;
        }
      }
    }
    if (unparkedCnt == 0) break;
    if (freeCell.row == -1) {
      moves.clear();
      break;
    }
    for (int imove = 0; imove < 2 * K; ++imove) {
      RC carCell;
      if (freeCell == RC(2, 1))
        carCell = RC(3, 1);
      else if (freeCell == RC(3, N))
        carCell = RC(2, N);
      else if (freeCell.row == 2)
        carCell = RC(2, freeCell.col - 1);
      else
        carCell = RC(3, freeCell.col + 1);
      const int icar = at(fld, carCell);
      if (icar != 0) moves.push_back(make_pair(icar, freeCell));
      at(fld, freeCell) = icar;
      at(fld, carCell) = 0;
      freeCell = carCell;
    }
  }
  cout << ((moves.empty() || moves.size() > 20000) ? (-1) : int(moves.size()))
       << '\n';
  for (const auto& pr : moves)
    cout << pr.first << ' ' << pr.second.row << ' ' << pr.second.col << '\n';
  cout.flush();
  return 0;
}
