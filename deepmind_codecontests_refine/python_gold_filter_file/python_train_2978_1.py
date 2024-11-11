n,s = map(int,input().split())
l = n+1
for i in range(s,min(s+1000000, n)+1,1):
    cur = sum([int(j) for j in str(i)])
    if(i-cur>=s):
        l = i; break
print(n-l+1)