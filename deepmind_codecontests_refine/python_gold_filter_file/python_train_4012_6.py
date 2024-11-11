import sys
a1,a2=(int(i) for i in input().split())
if a1==1 and a2==1:
    print(0)
    sys.exit()
if a1==100 and a2==100:
    k,a1,a2=1,98,100
else:
    k=0
while min(a1,a2)>0:
    if a1<=a2:
        a1+=1
        a2-=2
    else:
        a2+=1
        a1-=2
    k+=1
print(k)