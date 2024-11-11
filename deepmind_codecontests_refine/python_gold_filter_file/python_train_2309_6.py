n=int(input())
l=list(map(int,input().split()))
l.sort()
if l[0]>1:
    l[0]-=1
for i in range(1,n):
    if l[i]<=l[i-1]:
        l[i]+=1
    else:
        if l[i]-1>l[i-1]:
            l[i]-=1
s=set(l)
print(len(s))