n = int(input())
steward = list(map(int, input().split()))

mini = min(steward)
maxi = max(steward)
result = max(0, n-steward.count(mini)-steward.count(maxi))
print(result)

