w=list(map(int,input().split()))
e=((w[1]-w[3])**2+(w[2]-w[4])**2)**(1/2)
r=e//w[0]
if e%(2*w[0])==0:
    print(int(r//2))
else:
    print(int(r//2+1))