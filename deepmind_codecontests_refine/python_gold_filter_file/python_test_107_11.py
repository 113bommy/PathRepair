for i in range(int(input())):
    n,a,b=map(int,input().split())
    ans=[]
    if(a+b+2>n) or (abs(a-b)>=2):
        print("-1")
    else:
        if(a>b):
            for j in range(a):
                ans.append(j+1)
                ans.append(n-j)
            for j in range(n-2*a):
                ans.append(n-a-j)
        elif(a<b):
            for j in range(b):
                ans.append(n-j)
                ans.append(j+1)
            for j in range(n-2*b):
                ans.append(b+j+1)
        else:
            for j in range(a):
                ans.append(j+1)
                ans.append(n-j)
 
            for j in range(n-2*a):
                ans.append(a+j+1)
        print(*ans)
