n = int(input())
u = list(map(int, input().split()))
p2 = sum(u) + 1
k = max(u)
p1 = 0
for i in range(n):
    p1 += k - u[i]
def high(b):
    if b != int(b):
        b += 1
    return int(b)
print(high(max(0, p2 - p1) / n) + k)
            
