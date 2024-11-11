import math
h1,a1,c1 = map(int,input().split())
h2,a2 = map(int,input().split())
a = math.ceil(h1/a2);b = math.ceil(h2/a1)
if(b<=a):
    print(b)
    for i in range(b):
        print("STRIKE")
else:
    A=[]
    for i in range(a-1):
        A.append("STRIKE")
    h2 -= (a-1)*a1
    h1-=(a-1)*a2
    while(a<b):
        A.append("HEAL")
        h1+=c1
        h1-=a2
        a = math.ceil(h1/a2);b = math.ceil(h2/a1)
    for i in range(b):
        A.append("STRIKE")
    print(len(A))
    for i in A:
        print(i)