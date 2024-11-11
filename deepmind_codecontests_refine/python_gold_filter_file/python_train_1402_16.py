l,r=input().split(" ")
l=int(l)
r=int(r)
i=l
c=0
while i+2<=r:
    if i%2==0:
        print(i,i+1,i+2)
        c=1
        break
    else:
        i+=1
if c==0:
    print("-1")