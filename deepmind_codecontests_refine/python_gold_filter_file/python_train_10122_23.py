def solve():
    a, b = map(int, input().split())
    if a == b:
        print(0)
    elif a > b:
        if a % 2 == b % 2:
            print(1)
        else:
            print(2)
    else:
        if a % 2 == b % 2:
            print(2)
        else:
            print(1)
 
 
t = int(input())
for _ in range(t):
    solve()