t = int(input())
count = 0
for i in range(t):
    m, n = map(int,input().split())
    if n-m>1:
        count += 1
print(count)
