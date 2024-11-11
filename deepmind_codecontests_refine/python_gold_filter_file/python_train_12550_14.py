n, c = [int(x) for x in input().split()]
time = [int(x) for x in input().split()]
num = 1
for i in range(1, n):
    if time[i]-time[i-1] <= c:
        num = num+1
    else:
        num = 1
print(num)
