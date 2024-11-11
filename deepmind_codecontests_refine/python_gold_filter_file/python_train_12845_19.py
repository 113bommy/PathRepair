n, m = map(int,input().split())
tot  = n * (n-1) // 2
if m >= tot:
    print("no solution")
    exit()
for i in range(n):
    print(0, i)
# Tue Jul 07 2020 13:50:53 GMT+0300 (Москва, стандартное время)
