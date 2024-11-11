# T = int(input())
# while T > 0:
#     T -= 1
n, m = map(int, input().split())
a = list(input().split())
b = list(input().split())
q = int(input())
while q > 0:
    q -= 1
    x = int(input()) - 1
    print(a[x % n] + b[x % m])
