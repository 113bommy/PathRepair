[n, v] = [int(x) for x in input().split()]

cost = min(v,n-1)
tank = min(v,n-1)-1
for i in range(2,n):
    if i + tank >= n:
        ''
    else:

        cost += i
        tank += 1
    # print(i, tank)
    tank -= 1
print(cost)
