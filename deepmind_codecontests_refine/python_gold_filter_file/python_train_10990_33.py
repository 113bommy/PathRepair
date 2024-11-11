our = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
m, d = map(int, input().split())
m -= 1
days = our[m]
res = 1
days = days + d - 8
print((days - 1) // 7 + 2)