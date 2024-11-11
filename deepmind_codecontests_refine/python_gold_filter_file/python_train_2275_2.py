n = int(input())
a = list(map(int, input().split()))
if sum(a)%2:
    print("NO")
else:
    print("YES")