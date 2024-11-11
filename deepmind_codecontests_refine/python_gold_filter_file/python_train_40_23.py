a, b = map(int, input().split())
count = a
while count >= 0:
    count += a // b
    if a//b == 0:
        print(count)
        break
    a = a // b + a % b