t=int(input())
while t:
    l=list(input().strip())
    n=len(l)
    if(l[0]=='?' and 1<n):
        for i in ['a','b','c']:
            if(l[1]!=i):
               l[0]=i
               break
    elif(l[0]=="?" and n==1):
        l[0]='a'
    for i in range(1,len(l)-1):
        if(l[i]=='?'):
            for j in ['a','b','c']:
                if(j!=l[i-1] and j!=l[i+1]):
                    l[i]=j
    if(l[-1]=='?' and len(l)>=2):
        for i in ['a','b','c']:
            if(l[-2]!=i):
               l[-1]=i
               break
    lol=0
    for i in range(1,n):
        if(l[i]==l[i-1]):
            lol=1
            break
    if(lol==0):
        print("".join(l))
    else:
        print(-1)
    t-=1
            
    

        
            