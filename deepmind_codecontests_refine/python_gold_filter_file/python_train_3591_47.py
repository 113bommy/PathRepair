n,m = map(int, input().split())
if (n==1):
    print(1)
elif (n-m+1)/n > m/n:
    print(m+1)
else:
    print(m-1)
