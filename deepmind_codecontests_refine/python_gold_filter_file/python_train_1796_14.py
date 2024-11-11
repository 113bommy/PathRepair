t=int(input())
while t:
    t-=1
    n,k=map(int,input().split())
    if n%2!=0:
        if k%2==0:
            print("No")
        elif k>n:
            print("No")
        else:
            print("Yes")
            for i in range(k-1):
                print(1,end=" ")
            print(n-((k-1)))
    else:
        if k%2!=0:
            if 2*k>n:
                print("No")
            else:
                print("Yes")
                for i in range(k-1):
                    print(2,end=" ")
                print(n-(2*(k-1)))
        else:
            if 2*k<=n:
                print("yes")
                for i in range(k-1):
                    print(2,end=" ")
                print(n-(2*(k-1)))
            elif k<=n:
                print("Yes")
                for i in range(k-1):
                    print(1,end=" ")
                print(n-((k-1)))
                
            else:
                print("No")
                
                