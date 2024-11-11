n, m = map(int, input().split())
a = list(map(int, input().split()))

maxnum = [-1] * (n+1)
cost = [0,2,5,5,4,5,6,3,7,6]
maxnum[0] = 0
for i in range(n+1):
    for num in a:
        if ( i+cost[num] < n+1 ):
            maxnum[i+cost[num]] = max(maxnum[i+cost[num]], num + maxnum[i]*10)

print(maxnum[n])