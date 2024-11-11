a,b = map(int,input().split())
n = list(map(int,input().split()))
n.sort()
print(sum(n[-b:]))
