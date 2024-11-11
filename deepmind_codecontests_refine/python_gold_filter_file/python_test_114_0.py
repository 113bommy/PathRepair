t = int(input())
for idx in range(t):
    n = int(input())
    arr = []
    data = input().split(" ")
    for i in range(n):
        arr.append(int(data[i]))
    
    arr.sort()
    for i in range(1, n//2 + 1):
        print(arr[i], arr[0])
    