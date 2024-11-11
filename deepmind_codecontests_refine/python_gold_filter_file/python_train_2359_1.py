n = int(input().strip())
res = 0
i = 1
n -= 1
while i <= n:
    res += ((n-i)//(i << 1)+1)*i
    i <<= 1
print(res)