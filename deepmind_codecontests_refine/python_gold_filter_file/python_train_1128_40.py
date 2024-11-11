N = int(input())
A = list(map(int,input().split()))
C = [a//400 for a in A if a<3200]
m = len(set(C))
print(max(1,m),m+N-len(C))