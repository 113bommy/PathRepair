t=int(input())
while(t>0):
    t=t-1
    l=input().split()
    n=int(l[0])
    m=int(l[1])
    f=0
    for i in range(n):     
        a1=input().split()
        a2=input().split()
        a3=int(a1[1])
        a4=int(a2[0])
        if(a3==a4):
            f=1
            
    if(m%2!=0):
        print("NO")
    else:
        if(f==1):
            print("YES")
        else:
            print("NO")