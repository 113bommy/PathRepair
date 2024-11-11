a=input().split()

r=int(a[0])

x=int(a[1])
y=int(a[2])

x1=int(a[3])
y1=int(a[4])

dst= ((x1-x)**2 + (y-y1)**2)**(1/2)



if dst==0:
    print(0)
elif dst/(r*2) == dst//(r*2):
    print(int(dst//(r*2)))
else:
    print(int(dst//(r*2))+1)
