a,b=map(int,input().split())
if b<2 or b>2*a-2:print("No")
else:
    print("Yes")
    d=[i for i in range(1,b-1)]+[i for i in range(b+1,a+1)]+[b-1,b]+[i for i in range(a+1,2*a)]if 1<=b<a+1else[i for i in range(1,a)]+[b,b+1]+[i for i in range(a,b)]+[i for i in range(b+2,2*a)]
    for i in d:print(i)