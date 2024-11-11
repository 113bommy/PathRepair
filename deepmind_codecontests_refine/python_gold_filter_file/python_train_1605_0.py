def solve(lst, l, r, left, right):
    left_sum = [0]
    right_sum = [0] * (len(lst) + 1)

    cum_sum = 0
    for i in range(len(lst)):
        cum_sum += lst[i]
        left_sum.append(cum_sum)

    cum_sum = 0
    for i in reversed(range(len(lst))):
        cum_sum += lst[i]
        right_sum[i] = cum_sum

    #print(lst, left_sum, right_sum)
    min_cost = float('inf')
    for i in range(len(lst)+1):
        cost = left_sum[i] * l + right_sum[i]*r
        #print(i, cost, left_sum[i],l, right_sum[i], r)
        if i > n-i:
            cost += left * (2*i -n -1)
        elif i < n - i:
            cost += right *(n - 1- 2*i)
        #print(cost)
        min_cost = min(min_cost, cost)

    return min_cost

n, l, r, left, right = list(map(int, input().split()))
lst = list(map(int, input().split()))
print(solve(lst, l, r, left, right))