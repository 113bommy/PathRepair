n, k = map(int, input().split())
val = list(map(int, input().split()))
i = 1
while k > i:
    k -= i
    i += 1
print(val[k - 1])