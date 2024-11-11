import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

tmp = B[-1]
ok = True
if tmp != 0:
    for i in reversed(range(N)):
        b = B[i]
        if tmp-(N-1-i) > 0:
            if b != tmp-(N-1-i):
                ok = False
    for i in range(N-tmp):
        b = B[i]
        if b > 0 and b <= tmp + i+1:
            ok = False
else:
    ok = False
if ok:
    ans = N-tmp
else:
    ans = N
    for i, b in enumerate(B):
        if b != 0:
            ans = max(N-b+2+i, ans)
print(ans)