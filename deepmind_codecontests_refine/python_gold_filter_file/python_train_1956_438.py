N,K = map(int,input().split())
a = N%K

print(min(a,K-a))