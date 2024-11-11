t = int(input())

for q in range(t):
    n = int(input())
    arr = input().split()
    new = [int(arr[i]) for i in range(n)]
    x = 0
    for i in range(n-1):
        if new[i] != new[i+1]:
            x = 1
    if x == 1:
        print(1)
    else:
        print(n)