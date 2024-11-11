n, k = map(int, input().split())
h = list(map(int, input().split()))

opt = [0]
for i in range(1,n):
    opt += [min([opt[-j] + abs(h[i-j] - h[i]) for j in range(1,min(i,k)+1)])]
print(opt[-1])