n = int(input())
a = list(map(int, input().split()))
t = 0
for i in range(len(a)):
    if a[i] < 0:
        t += 1
        a[i] = -a[i]
if t % 2 == 0 or n % 2 == 1:
    print(sum(a))
else:
    print(sum(a) - min(a) * 2)