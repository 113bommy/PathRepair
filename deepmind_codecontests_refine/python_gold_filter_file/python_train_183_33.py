n=int(input())
l=list(map(int,input().split()))
d=list(map(int,input().split()))
k=list(map(int,input().split()))
s=sum(d)
for i in range(n-1):
    if(l[i]+1==l[i+1]):
        s+=k[l[i]-1]
print(s)
