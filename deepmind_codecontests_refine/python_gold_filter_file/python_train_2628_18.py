t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    if a == 1 or b == 1:
        print("YES")
        continue
    if a > 2 or b > 2:
        print("NO")
    else:
        print('YES')
