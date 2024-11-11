n=int(input())
h=[int(x) for x in input().split()]
cur=[0]*n
for i in range(1,n):
    if h[i]<=h[i-1]:
        cur[i]=cur[i-1]+1
print(max(cur))
