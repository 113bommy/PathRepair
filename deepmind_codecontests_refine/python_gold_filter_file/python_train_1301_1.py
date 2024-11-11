n,k=map(int, input().split())
m,r=[0] * 10, 0
for a in map(int, input().split()):
    m[a%10]+=1
    r += a // 10
for i in range(1, 10):
    x = min(k // i, m[10 - i])
    k -= x * i
    r += x
print(min(r + k // 10, 10 * n))