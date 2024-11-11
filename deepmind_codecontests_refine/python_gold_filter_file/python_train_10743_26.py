
t = int(input())

def f(n, m, prices):
    total_price = 0
    if m < n or n < 3:
        print(-1)
        return
    else:
        total_price += 2 * sum(prices)
        m -= n
        min1 = min2 = 10000
        in1 = in2 = -1
        i = 0
        for price in prices:
            if price < min1:
                min2 = min1
                min1 = price
                in2 = in1
                in1 = i
            elif price < min2:
                min2 = price
                in2 = i
            i += 1
        total_price += m * (min1 + min2)
        print(total_price)
        for num in range(1, n):
            print(num, num+1)
        print(1, n)
        if m > 0:
            for _ in range(m):
                print(in1, in2)
        return

for _ in range(t):
    n, m = map(int, input().split())
    prices = list(map(int, input().split()))
    f(n, m, prices)
