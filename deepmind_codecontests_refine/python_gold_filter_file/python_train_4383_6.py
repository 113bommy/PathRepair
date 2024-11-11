from collections import  defaultdict
n=int(input())
l=list(map(int,input().split()))
d=defaultdict(int)
for i in l:
    d[i]+=1
s=c=0
#d=sorted(d,key=d.values())
#print(d)
for i in sorted(d, key=d.get, reverse=True):
    if(c!=0):
        s+=d[i]
        continue
    c=1
print(s)



