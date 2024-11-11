r, d = map(int, input().split())
n = int(input())
k=0
for i in range(n):
    x, y, rr = map(int, input().split())
    if (x*x + y*y)**0.5-rr >= r-d and (x*x + y*y)**0.5 + rr <= r:
       k += 1

print(k)
