from fractions import gcd

n = int(input())
bids = list(map(int, input().split()))
a = bids[0]
for i in range(1, n):
    a = gcd(a, bids[i])
for i in bids:
    b = i//a
    while b%2 == 0:
        b = b//2
    while b%3 == 0:
        b = b // 3
    if b != 1:
        print("No")
        exit(0)
print("Yes")