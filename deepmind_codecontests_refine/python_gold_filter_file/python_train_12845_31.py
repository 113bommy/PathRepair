n,k=map(int,input().split())
maxi=(n*(n-1))/2
if k>=maxi:
    print("no solution")
    exit()
for i in range(n):
    print("0 {}".format(i))



