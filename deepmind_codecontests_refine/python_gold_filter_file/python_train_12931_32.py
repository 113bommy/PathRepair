n, m = [int(a) for a in input().split()]
s = input().split()
t = input().split()
k = int(input())

output = ''

for i in range(k):
    year = int(input())
    si = year % n
    ti = year % m
    if si == 0: si = n
    if ti == 0: ti = m
    output = output + s[si - 1] + t[ti - 1] + '\n'  
print(output)