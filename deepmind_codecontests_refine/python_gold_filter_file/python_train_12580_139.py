N,K =map(int,input().split())
l = sorted(list(map(int,input().split())))

print(sum(l[-1:-K-1:-1]))