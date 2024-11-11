def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)
n = int(input())
a = input().split(' ')
t = 0
for i in a:
    t = gcd(t, int(i))
if t != int(a[0]):
    print(-1)
else:
    print(2 * a.__len__())
    for i in a:
        print("%d %d" % (int(i), t), end=" ")