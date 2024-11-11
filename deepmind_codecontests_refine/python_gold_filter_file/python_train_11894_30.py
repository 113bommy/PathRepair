

def check(n):
    arr=[]
    if n%2==1:
        for i in range(1,n+1,2):
            print(i,end=" ")
    else:
        for i in range(2,n+1,2):
            print(i,end=" ")
    print(n-3,end=" ")
    print(n-1,end=" ")
    for i in range(n-5,0,-2):
        print(i,end=" ")
    print()
    
        


t=int(input())

for i in range(t):
    n=int(input())
    if n<=3:
        print(-1)
    else:
        check(n)

