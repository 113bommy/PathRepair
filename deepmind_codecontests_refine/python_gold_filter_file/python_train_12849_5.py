n,m=map(int,input().split())
l=[]
f=0
s=[]
for i in range(n):
    temp=input()
    sindex=temp.index("S")
    gindex=temp.index("G")
    if sindex<gindex:
        f=1
        break
    else:
        s.append(sindex-gindex)
    l.append(temp)
if f==1:
    print(-1)
else:
    s=set(s)
    print(len(s))