#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue, bisect
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

n = int(input())
a = sorted(map(int, input().split()))
ans = 10**10
for i in range(2*n):
    for j in range(i+1, 2*n):
        b = []
        for k in range(2*n):
            if k == i or k == j: continue
            b.append(a[k])
        b = sum([abs(b[i]-b[i-1]) for i in range(1, len(b), 2)])
        ans = min(ans, b)
print(ans)