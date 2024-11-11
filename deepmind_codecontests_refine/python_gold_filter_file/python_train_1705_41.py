n,m=map(int,input().split())

if n>m:
    print(m+1)
    for i in range(1,m+2):
        print(i,i-1)
elif(n==m):
    print(m+1)
    # print("y")
    for i in range(0,n+1):
        print(n-i,i)
    # print(m,0)
    
    
else:
    print(n+1)
    for i in range(0,n+1):
        print(i,i+1)


        
    