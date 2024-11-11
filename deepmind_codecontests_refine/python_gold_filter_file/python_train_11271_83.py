t=int(input())
for _ in range(t):
    n=int(input())
    a=input()
    s=""
    for i in range(0,2*n-1,2):
        s=s+a[i]
    print(s)
