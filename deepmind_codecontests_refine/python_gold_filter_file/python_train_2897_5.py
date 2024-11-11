n=int(input())
l=[]
for i in range(n):
    s=list(input())
    l.append(s+s)
ans=0
for i in range(n):
    f=0
    for h in range(n):
        for w in range(n):
            #0,0+i 1,1+i h,h+i
            if l[h][w+i]!=l[w][h+i]:
                f+=1
    if f==0:
        ans+=1
print(ans*n)
