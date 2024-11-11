def process(n,m):
    if n==1:
        print("0")
    elif n==2:
        print(m)
    else:
        print(2*m)
t=int(input())
for i in range(t):
    n,m=input().split()
    process(int(n),int(m))
