c2=c1=0
t=int(input())
while(t>0):
    c2=c1=0
    a=int(input())
    l1=list(map(int,input().split()))
    b=int(input())
    l2=list(map(int,input().split()))
    for i in l2:
        if(i%2==0):
            c1+=1
    for i in l1:
        if(i%2==0):
            c2+=1
    t-=1
    print((c1*c2)+(len(l2)-c1)*(len(l1)-c2))