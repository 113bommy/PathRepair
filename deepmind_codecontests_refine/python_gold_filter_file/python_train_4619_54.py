n = int(input())
count = 0
while n > 0:
    n -= 1
    k = input().split()
    if k.count('1') >= 2:
        count += 1
print(count)