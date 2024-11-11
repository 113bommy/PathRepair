n = int(input())
d = [1] * 100
a, b = map(int, input().split()) 
for tc in range(n - 1):
    l, r = map(int, input().split())
    for i in range(l, r):
        d[i] = 0
 
print(sum(d[a:b]))