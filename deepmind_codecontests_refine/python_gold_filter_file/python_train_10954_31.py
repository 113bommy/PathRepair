n=int(input())
l=list(map(int,input().split(' ')))
m={}
for i in range(n):
    p=l[i]-(i+1)
   
    if p in m:
        m[p].append(l[i])
    else:
        m[p]=[l[i]]
s=0
for i in m.keys():
        s=max(s,sum(m[i]))
print(s)
