n=int(input())
for j in range(n):
    s=input()
    l=r=d=u=0
    for i in s:
         if i=='L':
            l+=1
         if i=='R':
            r+=1
         if i=='U':
            u+=1
         if i=='D':
            d+=1
    l=r=min(l,r)
    u=d=min(u,d)
    if(r==0) and u!=0:
        print(2)
        print("UD")
    elif(u==0) and r!=0:
        print(2)
        print("RL")
    else:
        print(2*l+2*u)
        s=""
        for i in range(l):
            s+="L"
        for i in range(d):
            s+="D"
        for i in range(r):
            s+="R"
        for i in range(u):
            s+="U"
        print(s)
