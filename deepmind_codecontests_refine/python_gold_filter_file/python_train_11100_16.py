n, k = map(int, input().split())
x = list(map(int, input().split()))
flag = 0
cnt = k
while flag != n and cnt != 0:
    if x[0] > x[1]:
        x.append(x[1])
        del x[1]
        cnt -= 1
        flag += 1
    elif x[0] < x[1]:
        x.append(x[0])
        del x[0]
        cnt = k - 1
        flag = 0
print(x[0])
