from sys import stdin
T = int(input())
 
for _ in range(T):
    (n, s, k) = list(map(int, stdin.readline().rstrip().split(" ")))
    arr = list(map(int, stdin.readline().rstrip().split(" ")))
    

    
    minFloors = 10e9
    
    for i in range(s, n + 1):
        if i not in arr:
            minFloors = i - s
            break
    
    for i in range(s - 1, 0, -1):
        if i not in arr:
            if s - i < minFloors:
                minFloors = s - i
            break
    
    print(minFloors)