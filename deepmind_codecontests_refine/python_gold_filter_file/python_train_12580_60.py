n,k = map(int,input().split())
x = sorted(list(map(int,input().split())))
print(sum(x[:-k-1:-1]))