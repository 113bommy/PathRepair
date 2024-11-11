t=int(input())
for i in range(t):
    n1,k1=input().split(" ")
    n=int(n1)
    k=int(k1)
    if (k % (n-1)==0):
        print(n*(k // (n-1))-1)
    else:
        print(n*(k // (n-1))+(k % (n-1)))