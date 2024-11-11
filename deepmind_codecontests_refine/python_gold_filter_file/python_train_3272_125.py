n = int(input())
s = list(map(int, input().split()))
for i in range(n):
    for j in range(n-1):
        if s[j] > s[j+1]:
            s[j], s[j+1] = s[j+1], s[j]
print(*s)