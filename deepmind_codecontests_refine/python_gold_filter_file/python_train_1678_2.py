#Bad_Beast
t=int(input())
for _ in range(t):
    L,v,l,r=map(int,input().split())
    total=L//v
    t1=l//v
    t2=r//v
    remain=t2-t1
    if l%v==0:
        remain+=1
    print(total-remain)        