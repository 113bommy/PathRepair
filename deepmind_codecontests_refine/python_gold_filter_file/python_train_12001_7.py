def ii(): return int(input())
def li(): return list(map(int, input().split()))


t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = li()

    a.sort()

    count = 0
    for i in a[1:]:
        count += (k - i) // a[0]

    print(count)
