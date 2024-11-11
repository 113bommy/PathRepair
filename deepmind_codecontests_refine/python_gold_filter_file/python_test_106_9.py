t=int(input())
for i in range(t):
    a=int(input())
    b=[]
    for i in range(2,a+2):
        b.append(i)
    print(*b)
