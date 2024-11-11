x=input().split()
y=input().split()

a=int(x[0])
b=int(x[1])
c=0
for i in y:
    i=int(i)
    b=b-(86400-i)
    c=c+1
    if b<=0:
        print(c)
        break

