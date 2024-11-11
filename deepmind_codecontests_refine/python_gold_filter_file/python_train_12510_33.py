n,k = map(int,input().split())
n2 = 100000
ans = 0
n3 = int(k ** 0.5) - 2 
for i in range(max(0,n3-2),n2):
    temp = (i+1) * i / 2
    if temp  - n + i == k:
        ans = n - i
        break
print(ans)
