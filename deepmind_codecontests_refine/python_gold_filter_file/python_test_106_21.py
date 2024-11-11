t = int(input())

for _ in range(t):
    n = int(input())
    arr=[2]
    if(n==1):
        print(*arr)
    else:
        dummy=3
        for i in range(1,n):
            arr.append(dummy)
            dummy=dummy+1
        print(*arr)
    