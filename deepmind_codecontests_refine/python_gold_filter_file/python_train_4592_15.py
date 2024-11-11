t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    if a - b != 1:
        print("NO")
        continue
    c = a + b
    for t in range(2, int(c ** 0.5) + 1):
        if c % t == 0:
            print("NO")
            break
    else:
        print("YES")
