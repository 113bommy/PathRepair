import sys
n,k = map(int,input().split())
a = list(map(int,input().split()))
candies = left = cnt = 0
for i in range(n):
    candies = min(a[i]+left, 8, k)
    k -= candies
    left += a[i] - candies
    cnt += 1
    if k <= 0:
        break
if k <= 0:
    print(cnt)
else:
    print('-1')
    