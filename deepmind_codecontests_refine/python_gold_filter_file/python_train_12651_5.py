n=int(input())
a=[int(i) for i in input().split()]
d=set(a)
l=[]
f={}
for i in d:
    l.append(a.count(i))
e=max(l)
q=l.count(e)
if(q==1):
    for j in d:
        if(a.count(j)==e):
            print(j)
else:
    for j in range(0,len(a)):
        if(a[j] not in f):
            f[a[j]]=1
        else:
            f[a[j]]=f[a[j]]+1
        if(f[a[j]]==e):
            print(a[j])
            break
            