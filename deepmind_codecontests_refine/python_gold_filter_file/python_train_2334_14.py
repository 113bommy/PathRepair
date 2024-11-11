m = int(input()) * 2
l = [input() for i in range(4)]

for i in range(1, 10):
    if sum([l[j].count(str(i)) for j in range(4)]) > m:
        exit(print('NO'))

print('YES')
