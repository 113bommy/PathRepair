n = int(input())
r = list(map(int,input().split()))

r.sort()

print(r[n//2]-r[n//2-1])