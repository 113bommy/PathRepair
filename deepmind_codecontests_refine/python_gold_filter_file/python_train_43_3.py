n, a, b, c = list(map(int, input().split()))
 
res = 0
for x in range(c+1):
    for y in range(b+1):
        diff = n - 2*x - y
        if diff >= 0 and diff * 2 <= a:
            res+=1
print(res)