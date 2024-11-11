t1, t2 = map(int, input().split())
a1, a2 = map(int, input().split())
b1, b2 = map(int, input().split())

ng = "infinity"

first = t1 * a1 - t1 * b1
second = t1 * a1 + t2 * a2 - t1 * b1 - t2 * b2

if second == 0:
    print(ng)
    exit()

if first * second > 0:
    print(0)
    exit()

if first < 0:
    first *= -1
    second *= -1
second *= -1
ans = 2 * (first // second) + 1
if first % second == 0:ans -=1
print(ans)