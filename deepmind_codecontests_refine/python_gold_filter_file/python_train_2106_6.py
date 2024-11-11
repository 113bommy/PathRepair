def satisfyCustomers(customers):
    i, n = 1, len(customers)
    possible = [customers[0][1], customers[0][1]]
    prevTime = customers[0][0]
    while i < n:
        difference = customers[i][0] - prevTime
        minTime = customers[i][1]
        maxTime = customers[i][2]
        lo = possible[0] - difference
        hi = possible[1] + difference

#        while i + 1 < n and customers[i + 1][0] == customers[i][0]:
#            minTime = min(minTime, customers[i][1], customers[i][2])
#            maxTime = max(maxTime, customers[i][1], customers[i][2])
#            i += 1
       
        
        new_lo = max(minTime, lo)
        new_hi = min(maxTime, hi)
        if new_hi < new_lo: return False
                    
        prevTime = customers[i][0]
        possible = [new_lo, new_hi]
        i += 1
    return True

#customers = [(0, 12, 12), (5, 7, 10), (10, 16, 20)]
#customers = [(0, -100, -100), (100, 0, 0), (100, -50, 50), (200, 100 ,100)]
#customers = [(0, 10, 10), (8, -8, 7), (16, -10, -5)]
#print(satisfyCustomers(customers))

testCases = int(input())
for _ in range(testCases):
    n, m = map(int, input().split())
    customers = [(0, m, m)]
    for _ in range(n):
        t, l, h = map(int, input().split())
        customers.append([t, l, h])
    print('YES') if satisfyCustomers(customers) else print('NO')
