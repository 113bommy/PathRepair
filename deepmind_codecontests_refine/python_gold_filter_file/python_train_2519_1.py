t=int(input())
for i in range(t):
    a,b,n,s=map(int,input().split())
    if((a*n+b)<s):
       print("NO")
    else:
        if(s//n<=a and (s-n*(s//n))<=b):
            print("YES")
        elif(s//n>a and (s-a*n)<=b):
            print("YES")
        else:
            print("NO")
     