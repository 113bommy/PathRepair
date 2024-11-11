temp_numbers = list(map(int,input().split()))
n, m = temp_numbers[0], temp_numbers[1]

cost = list(map(int,input().split()))

min_cost = 3.1*10**6

adj = [[0 for i in range(n)] for j in range(n)]

for i in range(m):
    temp_input = list(map(int,input().split()))
    adj[temp_input[0]-1][temp_input[1]-1] = 1
    adj[temp_input[1]-1][temp_input[0]-1] = 1

for i in range(n-2):
    for j in range(i+1,n-1):
        for k in range(j+1,n):
            if adj[i][j] == adj[j][k] == adj[k][i] == 1 :
                min_cost = min(min_cost, cost[i] + cost[j] + cost[k])


if min_cost <= 3*10**6:
    print(min_cost)
else:
    print(-1)
