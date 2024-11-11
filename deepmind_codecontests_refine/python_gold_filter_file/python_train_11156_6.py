n = int(input())

def prime(x):
    for i in range(2, x):
        if x % i == 0:
            return False
    return True

p = n
while not prime(p):
    p += 1
print(p)
for i in range(1, n):
    print(i, i + 1)
print(1, n)
for i in range(1, p - n + 1):
    print(i, n - i)
