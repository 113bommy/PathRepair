queue = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]

n = int(input())
p = 0
while 5 * (2 ** p) < n:
    n -= 5 * (2 ** p)
    p += 1
print(queue[(n - 1) // (2 ** p)])