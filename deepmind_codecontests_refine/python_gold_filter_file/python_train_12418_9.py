T = int(input())

for t in range(T):
    n,k = [int(k) for k in input().split()]
    
    arr = sorted([int(k) for k in input().split()])
    
    total = 0
    for i in range(k):
        total += arr[len(arr)-(n//2 + 1)*(i+1)]
    print(total)