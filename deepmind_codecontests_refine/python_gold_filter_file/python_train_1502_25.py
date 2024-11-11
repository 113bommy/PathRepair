s=input()
bread=s.count("B")
cheese=s.count("C")
sauce=s.count("S")
b,s,c=map(int,input().split())
pb,ps,pc=map(int,input().split())
amount=int(input())
lo=0
hi=10**14
def bs(m):
    r=amount
    tempbread=bread*m
    tempcheese=cheese*m
    tempsauce=sauce*m
    if tempbread>b:
        reqb=tempbread-b
        if pb*reqb>r:
            return False
        r-=reqb*pb
    if tempcheese>c:
        reqc=tempcheese-c
        if pc*reqc>r:
            return False
        r-=reqc*pc
    if tempsauce>s:
        reqs=tempsauce-s
        if ps*reqs>r:
            return False
    return True
while(lo<=hi):
    m=lo+(hi-lo)//2
    if bs(m):
        lo=m+1
    else:
        hi=m-1
print(hi)
        