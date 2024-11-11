def solve(n, a, b):
    letters = "abcdefghijklmnopqrstuvwxyz"

    options = letters[:b] 
    
    result = []
    for i in range(n):
        result.append(options[i%len(options)])
    return "".join(result)

    
t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())
    result = solve(n, a, b)
    print(result)