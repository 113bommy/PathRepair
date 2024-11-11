n,t=map(int,input().split())
a=list(map(int,input().split()));c=0
for i in range(n) :
    if t<=0 :
        break
    else :
        t-=(86400-a[i])
        c+=1
print(c)
