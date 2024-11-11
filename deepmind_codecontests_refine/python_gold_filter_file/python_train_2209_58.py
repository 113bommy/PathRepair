t=int(input())
for _ in range(t):
    n=int(input())
    if n%9==0:
        print(int(n/0.9)-1)
    else:
        print(int(n/0.9))
    