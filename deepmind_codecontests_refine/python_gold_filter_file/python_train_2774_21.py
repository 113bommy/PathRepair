# import sys
# sys.stdin = open('in.txt', 'r')

n, k = map(int, input().split())
a = list(map(int, input().split()))

res = 0
res_i = 0
for i in range(len(a)):
    if (n // a[i]) * a[i] > res:
        res = (n // a[i]) * a[i]
        res_i = i

print(res_i+1, n // a[res_i])
