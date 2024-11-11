#include <bits/stdc++.h>
const int maxn = 100005;
int Q, L, R, A_lstA[maxn], A_totBC[maxn], B_lstA[maxn], B_totBC[maxn], _A_lstA_,
    _A_totBC_, _B_lstA_, _B_totBC_;
char A[maxn], B[maxn];
inline void read(int &Res) {
  char ch = getchar();
  for (Res = 0; !isdigit(ch); ch = getchar())
    ;
  for (; isdigit(ch); ch = getchar()) Res = (Res << 3) + (Res << 1) + ch - 48;
}
inline void Work() {
  for (int i = 1; A[i]; ++i)
    A_totBC[i] = A_totBC[i - 1] + (A[i] == 'B' || A[i] == 'C'),
    A_lstA[i] = A[i] == 'A' ? A_lstA[i - 1] + 1 : 0;
  for (int i = 1; B[i]; ++i)
    B_totBC[i] = B_totBC[i - 1] + (B[i] == 'B' || B[i] == 'C'),
    B_lstA[i] = B[i] == 'A' ? B_lstA[i - 1] + 1 : 0;
}
int main() {
  for (scanf("%s%s%d", A + 1, B + 1, &Q), Work(); Q; --Q) {
    read(L), read(R), _A_lstA_ = std::min(R - L + 1, A_lstA[R]),
                      _A_totBC_ = A_totBC[R] - A_totBC[L - 1];
    read(L), read(R), _B_lstA_ = std::min(R - L + 1, B_lstA[R]),
                      _B_totBC_ = B_totBC[R] - B_totBC[L - 1];
    if (_A_lstA_ < _B_lstA_ || _A_totBC_ > _B_totBC_ ||
        ((_A_totBC_ & 1) ^ (_B_totBC_ & 1)))
      putchar('0');
    else if ((_A_lstA_ > _B_lstA_ && _A_totBC_ < _B_totBC_) ||
             ((_A_totBC_ || !_B_totBC_) && (_A_lstA_ - _B_lstA_) % 3 == 0))
      putchar('1');
    else
      putchar('0');
  }
  return 0;
}
