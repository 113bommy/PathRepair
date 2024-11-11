t = int(input())

for i in range(t):
    n, k = tuple(int(i) for i in input().split())
    string = input()
    dp = [0 if string[0] == '1' else 1]
    c = 0
    for i in range(1, len(string)):
        if string[i] == '1':
            c = 0
            if i - k - 1 >= 0:
                dp.append(dp[i-k - 1])
            else:
                dp.append(0)
        else:
            c += 1
            dp.append(dp[i-1])
            if c > k:
                dp[-1] += 1
                c = 0
    print(dp[-1])
