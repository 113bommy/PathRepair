n = int(input())
count = 0
while n:
    flags = input().split()
    score = 0
    for f in flags:
        if f == '1':
            score += 1
    if score > 1:
        count += 1
    n -= 1
print(count)
