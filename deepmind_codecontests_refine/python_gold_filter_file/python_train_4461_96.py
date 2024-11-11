X = list(map(int,input().split()))
X.sort()
print(sum(X)-X[1]*2)