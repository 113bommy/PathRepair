n = int(input())
a = list(map(int, input().split()))
a = sorted(a)

if (sum(a) % 2 == 0 and sum(a[:-1]) >= a[-1]):
    print("YES")
else:
    print("NO")
