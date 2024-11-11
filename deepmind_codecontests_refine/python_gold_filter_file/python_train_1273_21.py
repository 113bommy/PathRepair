from bisect import bisect_left
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
amb = [a[x]-b[x] for x in range(n)]
amb.sort()
res=0
for i in range(n):
    if amb[i] <= 0:
        continue
    res += i - bisect_left(amb, -amb[i]+1)
print(res)
