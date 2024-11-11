n=int(input())
h=list(map(int, input().split()))
cur=[0]*n
for i in range(1,n):
    if h[i]<=h[i-1]:
        cur[i]=cur[i-1]+1
print(max(cur))
