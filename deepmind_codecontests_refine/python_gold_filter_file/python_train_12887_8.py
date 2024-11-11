import bisect
n=int(input())
l=sorted(list(map(int,input().split())))
cnt=0
for i in range(n-1):
  for j in range(i+1,n):
    a=l[i]
    b=l[j]
    c=bisect.bisect_left(l,a+b)
    cnt+=c-1-j
print(cnt)
