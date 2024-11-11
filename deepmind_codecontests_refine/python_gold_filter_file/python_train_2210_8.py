from collections import defaultdict
n=int(input())
a=list(map(int,input().split()))
d=defaultdict(int)
for i in a:
    d[i]+=1
ans=0
z = [i for i in d.keys()]
for i in z:
    if(i==0):
        ans+=(d[i]*(d[i]-1))
    else:
        ans+=(d[i]*d[-i])
print(ans//2)
