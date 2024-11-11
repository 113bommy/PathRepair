n = int(input())

a = list(map(int, input().split()))
s = sum(a)

if not(s&1) and max(a) <= s-max(a):
    print("YES")
else:
    print("NO")
