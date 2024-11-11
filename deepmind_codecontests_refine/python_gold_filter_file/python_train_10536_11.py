t=int(input())
for i in range(t):
    a=input().strip()
    x=[0 for _ in range(4)]
    s=""
    for i in a:
        if i=="L":
            x[0]+=1
        elif i=="R":
            x[1]+=1
        elif i=="D":
            x[2]+=1
        elif i=="U":
            x[3]+=1
    f=min(x[0],x[1])
    g=min(x[2],x[3])
    
    if f==0:
        if x[2]>0 and x[3]>0:
            print(2)
            print("UD")
        else:
            print(0)
            print(s)
    elif g==0:
        if x[0]>0 and x[1]>0:
            print(2)
            print("LR")
        else:
            print(0)
            print(s)
        
    else:
        print(2*f+2*g)
        for j in range(f):
            s+="R"
        for j in range(g):
            s+="U"
        for j in range(f):
            s+="L"
        for j in range(g):
            s+="D"
        print(s)
        
