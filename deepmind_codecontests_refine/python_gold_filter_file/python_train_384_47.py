n = int(input())
p = sorted(list(map(int, input().split())))
c1, c0 = 0, 0
for i in range(n//2):
    c1 += abs(2*i+1-p[i])
    c0 += abs(2*(i+1) - p[i])
print(min(c0, c1))