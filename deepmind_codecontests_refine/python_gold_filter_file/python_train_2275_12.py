n = int(input())
l = list(map(int, input().split()))

if sum(l)%2 == 0:
    print("YES")
else:
    print("NO")
