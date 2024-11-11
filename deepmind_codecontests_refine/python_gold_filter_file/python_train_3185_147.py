a,b=list(map(int,input().split()))
c=1
while 3*a-2*b<=0:
    a*=3
    b*=2
    c+=1
print(c)
