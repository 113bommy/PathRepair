n = int(input())
a = sorted(list(map(int, input().split())))

s = 1
l=10**18

for i in a:
    s *= i
    if s > l:
        print(-1)
        exit()
print(s)