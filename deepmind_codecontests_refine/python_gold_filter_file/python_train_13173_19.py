n,d=map(int,input().split())
res=0
c=0
val=False
for i in range(d):
    s=input()
    if s.count('1')!=n:
        c+=1

    else:
        if c>res:
            res=c
        c=0
        val=True
if not val:
    print(c)
else:
    print(max(res,c))