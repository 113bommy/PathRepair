from sys import stdout

n = int(input())
if n % 4 == 2:
    print("! -1")
    exit(0)
print("?", 1)
stdout.flush()
a = int(input())
print("?", 1 + n // 2)
stdout.flush()
b = int(input())
if a == b:
    print("!", 1)
    exit(0)
l = 1
r = 1 + n // 2
while(l != r):
    mid = ( l + r ) // 2
    print("?", mid)
    stdout.flush()
    c = int(input())
    print("?", mid + n // 2)
    stdout.flush()
    d = int(input())
    if c == d:
        print("!", mid)
        exit(0)
    if a < b:
        if c < d:
            l = mid + 1
        else:
            r = mid
    else:
        if c > d:
            l = mid + 1
        else:
            r = mid
print("!", l)