t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    if k==0:
        print(n)
    elif n%2==0 and k%4==2:
        print(n+1)
    elif n%2==0 and k%4==3:
        print(n+k+1)
    elif n%2==0 and k%4==0:
        print(n)
    elif n%2==0 and k%4==1:
        print(n-k)
    elif n%2==1 and k%4==2:
        print(n-1)
    elif n%2==1 and k%4==3:
        print(n-(k+1))
    elif n%2==1 and k%4==0:
        print(n)
    elif n%2==1 and k%4==1:
        print(n+k)