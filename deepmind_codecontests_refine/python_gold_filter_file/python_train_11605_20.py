a, m = map(int, input().split())
freq = [False for x in range(10**5 + 4)]
y = (2 * (a % m))%m
for _ in range(10**5 + 5):
    y = (2 * y) % m
    if y == 0:
        print("Yes")
        exit(0)
print("No")
