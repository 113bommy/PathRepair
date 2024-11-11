import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    a = sorted([int(i) for i in sys.stdin.readline().split()])
    ans = [0]*n
    for i in range(n//2):
        ans[2*i] = str(a[i])
        ans[2*i+1] = str(a[-i-1])
    if n%2 == 1:
        ans[-1] = str(a[n//2])
    print(" ".join(ans[::-1]))

