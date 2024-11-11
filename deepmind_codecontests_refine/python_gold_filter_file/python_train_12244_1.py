n,k=map(int,input().split())
a=input()
d={}
count='YES'
for i in a:
    d[i]=d.get(i,0)+1
for i in d.values():
    if i-k>0:
        count='NO'
print(count)
