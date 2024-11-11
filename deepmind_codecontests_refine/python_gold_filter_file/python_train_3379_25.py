n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
s = a[1:] + b[1:]
x = 0
for i in range(1,n+1):
    if(s.count(i) == 0):
        break
    if i == n:
        x = 1
print('I become the guy.' if (x == 1) else ('Oh, my keyboard!'))