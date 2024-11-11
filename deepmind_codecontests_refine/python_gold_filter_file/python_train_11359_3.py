import math
n = int(input())
a = list(map(int,input().split()))
x,tc = map(int,input().split())
ans = 0
for i in range(n):
    if a[i] > x:
        ans += math.ceil((a[i] - x)/(x + tc))
print(ans*tc)