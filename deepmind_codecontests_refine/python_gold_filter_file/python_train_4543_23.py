n, m, k = map(int, input().split())
if (n+m)%2==1 and k == -1:
    print(0)
else:
    print(pow(2, (m-1)*(n-1), 1000000007))
