n = int(input())
D = list(map(int,input().split()))

D.sort()
print(D[n//2] -D[n//2-1])

