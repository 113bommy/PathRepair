x,y=map(int,input().split())
mi=999999999999
for i in range(int(input())):
    a,b,c=map(int,input().split())
    t=((x-a)**2+(y-b)**2)**(0.5)/c
    if t<mi:mi=t
print(round(mi,20))
