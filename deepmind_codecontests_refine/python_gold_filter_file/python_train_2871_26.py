n = int(input())
l = list(map(int, input().split()))

limit = len(l)//2

for i in range(1,limit+1):
    if i % 2 != 0:
        l[i-1], l[(n-i+1)-1] = l[(n-i+1)-1], l[i-1]

print(*l)