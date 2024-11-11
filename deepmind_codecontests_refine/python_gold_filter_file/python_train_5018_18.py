T = int(input())
for i in range(T):
    a, b = map(int, input().split())
    r = a - b
    if r < 0:
        r -= 2 * r
    print(r // 5 + (r % 5) // 2 + (r % 5) % 2)