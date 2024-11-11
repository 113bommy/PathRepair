n = int(input())
a = [0] + list(map(int, input().split()))
def pi(i):
    global a, n
    s = f"node {i}: key = {a[i]}, "
    if i != 1:
        s += f"parent key = {a[int(i / 2)]}, "
    if i * 2 <= n:
        s += f"left key = {a[2 * i]}, "
        if i * 2 + 1 <= n:
            s += f"right key = {a[2 * i + 1]}, "
    print(s)

for i in range(1, n + 1):
    pi(i)
