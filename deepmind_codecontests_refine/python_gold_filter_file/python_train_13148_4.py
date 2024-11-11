t=int(input())

for _ in range(t):
    
    n,p,q=map(int,input().split())
    
    ob=list(map(int,input().split()))
    c=0
    if(len(set(ob))==1):
        print(min(p+q,2*q))
    else:
        for i in range(len(ob)-1):
            if(abs(ob[i]-ob[i+1])>1):
                c=1
                break
        if(c):
            if(ob[n-2]==1000001 and ob[n-1]==1000000):
                print(min(p,q))
            else:
                print(0)
        else:
            print(min(p,q))