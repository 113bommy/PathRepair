# python3 (3.4.3)
import sys
input = sys.stdin.readline

# main
N = int(input())
S = int(input())

def f(b,n):
    if n < b:
        return n
    else:
        return f(b, n//b) + n%b

ans = -1
if S==N:
    ans = N+1
else:
    # bをN^(1/2)まで全探索
    for b in range(2, int(N**.5)+1):
        if f(b,N)==S:
            ans = b
            break

# まだ答えが見つからなければ
if ans == -1:
    # bがN^(1/2)より大きい可能性が残っており、b進数で表すと2桁
    # 1 <= p < b, N = pb+q <= pb < p^2, p > N^(1/2) なので pで全探索
    # p+q = S より b = (N-S)/p+1
    for p in range(int(N**.5)+1,0,-1):
        b = (N-S)//p + 1
        # bが1のときは対象外にしないと無限ループ！
        if b >= 2 and f(b,N)==S:
            ans = b
            break

print(ans)
