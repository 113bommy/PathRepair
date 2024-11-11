n = int(input())
a = list(map(int, input().split()))[:n]
b = list(map(int, input().split()))[:n]
sa = sum(a)
b = sorted(b, reverse=True)
if (b[0] + b[1]) >= sa:
    print("YES")
else:
    print("NO")