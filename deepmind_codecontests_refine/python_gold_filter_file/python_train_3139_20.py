import sys
sys.setrecursionlimit(20000000)
input = sys.stdin.readline
H,n = map(int,input().split())
a = list(map(int,input().split()))
MIN = 0
ima = 0
for i in range(n):
    ima += a[i]
    MIN = min(MIN,ima)
MIN *= -1
ima *= -1
if H <= MIN:
    now = 0
    for i in range(n):
        now -= a[i]
        if H <= now:
            print(i+1)
            exit()
if ima <= 0:
    print(-1)
    exit()
H-=MIN

ans = (H//ima+1)*n
H %= ima
if H == 0:
    ans -= n
    H+=ima
H-=ima
H += MIN
now = 0
for i in range(n):
        now -= a[i]
        if H <= now:
            print(ans+i+1)
            exit()