def bitstring(k, n, s):
    arr = [-1 for i in range(k)]
    
    for i in range(n):
        if s[i] == "0":
            if arr[i%k] == 1:
                return "NO"
            arr[i%k] = 0
        elif s[i] == "1":
            if arr[i%k] == 0:
                return "NO"
            arr[i%k] = 1
            

    if arr.count(0) > k//2 or arr.count(1) > k//2:
        return "NO"
    return "YES"
    
    
t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    s = input()
    print(bitstring(k, n, s))
