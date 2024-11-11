# cook your dish here
t = int(input())
for _ in range(t):
    n = int(input())
    arr = []
    for i in range(1,n+1):
        arr.append(i)
    if n%2 == 0:
        for i in range(0,n,2):
            arr[i],arr[i+1] = arr[i+1],arr[i]
    else:
        for i in range(0,n-1,2):
            arr[i],arr[i+1] = arr[i+1],arr[i]
        arr[n-1],arr[n-2] = arr[n-2],arr[n-1]
    print(*arr)
    
        
        