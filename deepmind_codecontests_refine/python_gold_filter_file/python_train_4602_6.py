t=int(input())
for i in range(t):
    o1=0
    o2=0
    e1=0
    e2=0
    n1=int(input())
    l1=[int(i) for i in input().split()]
    n2=int(input())
    l2=[int(i) for i in input().split()]
    for j in l1:
        if j%2==1:
            o1+=1
        else:
            e1+=1
    for j in l2:
        if j%2==0:
            e2+=1
        else:
            o2+=1
    print((o1*o2)+(e1*e2))