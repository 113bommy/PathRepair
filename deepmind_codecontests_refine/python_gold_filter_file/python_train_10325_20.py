n = int(input())
a = list(map(int, input().split()))
a.sort()
if (sum(a) - a[-1] < a[-1] or sum(a)%2 == 1):
    print("NO")
else :
    print("YES")
