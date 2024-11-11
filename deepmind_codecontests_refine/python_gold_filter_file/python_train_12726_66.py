t=int(input())
for test in range(t):
    n,p=map(int,input().split())
    if n==1:
        print("0")
    elif n==2:
        print(p)
    else:
        print(2*p)