n=int(input())
d={}
a=[int(j)+1 for j in input().split()]
for i in range(n):
    if (a[i]!=0):
        d[a[i]]=i
mi=-1
for key in d:
    if ((mi==-1) or (d[key]<d[mi])):
        mi=key;
print(mi-1)