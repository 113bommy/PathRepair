n = int(input())
a = list(map(int, input().split()))
count = [0] * 101
for i in a:
    count[i] += 1
# print(count)
for i in range(len(count)):
    if count[i] > 0:
        # print(i, count[i])
        print((str(i) + ' ') * count[i], end='')