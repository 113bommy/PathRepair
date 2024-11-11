a = int(input())
b = int(input())
c = int(input())

n = 0
while n + 1 <= a and (n + 1) * 2 <= b and (n + 1) * 4 <= c:
    n += 1

print(7 * n)