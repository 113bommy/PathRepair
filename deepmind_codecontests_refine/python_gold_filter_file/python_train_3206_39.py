t,a,k = map(int, input().split())
T = max(t - k,0)
k-=t-T
A = max(a - k,0)
print(T,A)