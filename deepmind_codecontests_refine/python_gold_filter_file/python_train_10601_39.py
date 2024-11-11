x, y = map(int, input().split())
num = 0
while x <= y:
    x *= 2
    num += 1
print(num)