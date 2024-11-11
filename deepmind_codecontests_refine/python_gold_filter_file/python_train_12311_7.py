t = int(input())

for _ in range(t):
    a,b,c = map(int, input().split())
    
    if a == b and b == c and c == 1:
        print(-1,-1)
    elif a * b <= c:
        print(1, -1)
        continue
    elif c <= a:
        print(-1, b)
        continue
    else:
        print(1,b)