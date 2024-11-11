n = int(input())
min_n = 2 * 10**9
max_n = -2 * 10**9
for i in range(n):
    x = int(input())
    max_n = max(max_n,x - min_n)
    min_n = min(x,min_n)
print (max_n)