a,b=map(int,input().split())
c=[]
cnt=0
for i in range(1,a+1):
    l=list(map(int,input().split()))
    s=l[1:]
    x=sorted(s)
    if b>x[0]:
        c.append(str(i))
        cnt+=1
print(cnt)
print(" ".join(c))

