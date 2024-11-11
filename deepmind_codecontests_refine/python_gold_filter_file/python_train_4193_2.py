test_cases = int(input())
for e in range(test_cases):
    n, m = map(int,input().split())
    c = 0
    for i in range(n):
        direction = list(input())
        if direction[m-1] == "R":
            c += 1
    for i in range(m):
        if direction[i] == "D":
            c += 1
    print(c)
