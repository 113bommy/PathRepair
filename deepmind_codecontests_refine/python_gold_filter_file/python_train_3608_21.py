n = int(input())
a = list(map(int, input().split()))
s = sum(a)
t = 0
for i, val in enumerate(a):
    t += val
    if t >= s/2:
        print(i+1)
        break