from sys import stdin
def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i = i + 6
    return True


x, y = map(int, stdin.readline().rstrip().split(" "))

if not y%2:
    start =y-1
else:
    start = y
c = 0
for i in range(start, x, -2):
    if is_prime(i):
        c = i
        break

if c == 0:
    print(-1)
else:
    for i in range(start, y-y%c, - 2):
        check = False
        for j in range(3,x+1,2):
            if i%j==0:
                check=True
                break
        if not check:
            c = i
            break
    print(c)