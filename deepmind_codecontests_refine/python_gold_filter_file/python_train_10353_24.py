n,m=map(int,input().split());o=[]
for i in range(n):
    a=list(map(int,input().split()))
    t=10**9
    for j in range(1,len(a)):t=min(t,a[j])
    if(t<m):o.append(i+1)
print(len(o))
for i in range(len(o)):print(o[i],end=' ')