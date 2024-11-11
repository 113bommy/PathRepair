n = int(input())
l = list(map(int, input().strip().split()))[:n]
for i in range(n):

    mx = max(abs(l[i] - l[0]), abs(l[i] - l[-1]))

    if i == 0:
        mn = abs(l[i]-l[i+1])

    elif i == n-1:
        mn = abs(l[i] - l[i-1])

    else:
        mn = min(abs(l[i] - l[i + 1]), abs(l[i] - l[i-1]))


    print(mn, mx)