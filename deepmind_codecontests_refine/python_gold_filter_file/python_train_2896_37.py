n,k = map(int,input().split())
a = list(map(int,input().split()))
sal = [0] * (n*(n+1)//2)
l = 0
for i in range(n):
  for j in range(i,n):
    sal[l] = sum(a[i:j+1])
    l += 1
ans = 0
for i in range(41)[::-1]:
    cnt = 0
    temp = ans + 2**i
    for j in sal:
        if temp&j == temp:
            cnt += 1
    if cnt >= k:
        ans = temp
print(ans)
