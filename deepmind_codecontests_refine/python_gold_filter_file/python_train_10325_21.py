n = int(input())
k = list(map(lambda x: int(x), input().split()))
if sum(k) % 2 == 0 and max(k) * 2 <= sum(k):
    print("YES")
else:
    print("NO")