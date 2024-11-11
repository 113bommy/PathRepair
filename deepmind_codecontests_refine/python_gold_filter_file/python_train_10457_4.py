K,A,B=list(map(int,input().split()))
s=(input())
l=len(s)
if(A<=(l//K)<=B):
    temp=0
    save=0
    for i in range(A,B+1):
        p=l-(K-1)*i
        if(A<=p<=B):
            temp=1
            save=i
            break
    if(temp==1):
        t=0
        for j in range(K-1):
            print(s[t:t+i])
            t+=i
        print(s[t:l])
    else:
        print("No solution")
    # if(p!=0 and (p<A or p>B)):
    #     print("No Solution")
    # else:
    #     for i in range(K-1):
            
else:
    print("No solution")