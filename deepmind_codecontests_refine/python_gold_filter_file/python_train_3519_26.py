n,k = map(int,input().split())
v = [int(i) for i in input().split()]
jewel = []
ans = 0
for i in range(min(k+1,n+1)):
  for j in range(min(k-i+1,n-i+1)):
    jewel = v[:i] + v[:-(j+1):-1]
    jewel.sort()
    temp = sum(jewel)
    leng = len(jewel)
    for m in range(k-i-j):
      if leng > m and jewel[m] < 0:
        temp += -jewel[m]
    ans = max(ans,temp)
print(ans)