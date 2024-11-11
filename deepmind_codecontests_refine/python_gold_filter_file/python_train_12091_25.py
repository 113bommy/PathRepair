n,m,k = map(int, input().split())
ls = sorted(list(map(int, input().split())))
print((ls[-1]*k+ls[-2])*(m//(k+1)) + ls[-1]*(m%(k+1)))