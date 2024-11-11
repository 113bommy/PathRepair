n,x,y=map(int,input().split())
doors=list(map(int,input().split()))
doors.sort()
k=0
if x>y:
    k=n
elif x<=y:
    for door in doors:
        if door<=x:
            k+=1
    k=(k+1)//2
print(k)