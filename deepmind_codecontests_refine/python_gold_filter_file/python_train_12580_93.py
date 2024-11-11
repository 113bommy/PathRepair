N,K=map(int,input().split())
m=list(map(int,input().split()))
m.sort(reverse=True)
print(sum(m[:K]))