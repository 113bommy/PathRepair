n=int(input())
if(n%2==0):
    print("NO")
else:
    print("YES")
    arr=[1]*(2*n)
    for i in range(0,2*n,2):
        arr[i]=i+1
    num = 2
    for i in range(n, 2*n, 2):
        arr[i] = num
        num += 2
    for i in range(1, n, 2):
        arr[i] = num
        num += 2

    print(*arr)
    
