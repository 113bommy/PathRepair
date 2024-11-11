from fractions import gcd

n, m = map(int, input().split())
a = list(map(int, input().split()))
l = 1
num = a[0]
bin = 1
while num % 2 == 0:
    bin *= 2
    num //= 2
for num in a:
    l = (l * num // 2) // gcd(l, num // 2)
    if num % bin != 0 or num % (bin * 2) == 0:
        print(0)
        exit()
print((m + l) // (2 * l))
