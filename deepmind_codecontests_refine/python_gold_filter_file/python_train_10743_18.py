#Bhargey Mehta (Junior)
#DA-IICT, Gandhinagar
import sys, math
MOD = 10**9+7
#sys.stdin = open('input.txt', 'r')

for _ in range(int(input())):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    a = [(a[i], i+1) for i in range(n)]
    a.sort()
    if n == 2 or m < n:
        print(-1)
        continue
    total, ans = 0, []
    while len(a) > m:
        ans.append((a[0][1], a[-1][1]))
        ans.append((a[1][1], a[-1][1]))
        total += a[0][0]+a[-1][0]
        total += a[1][0]+a[-1][0]
        m -= 2
        a.pop()
    for i in range(len(a)):
        ans.append((a[i-1][1], a[i][1]))
        total += a[i-1][0]+a[i][0]
        m -= 1
    while m > 0:
        ans.append((a[0][1], a[1][1]))
        total += a[0][0]+a[1][0]
        m -= 1
    print(total)
    for chain in ans:
        print(*chain)