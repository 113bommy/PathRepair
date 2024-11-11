n,h = (int(i) for i in input().split(' '))
heights = [int(i) for i in input().split(' ')]
cnt = 0
for i in heights:
    if i <= h:
        cnt += 1
    else:
        cnt += 2
print(cnt)