I=lambda:map(int,input().split())
n,s=I()
print(max(max(sum(I()),s)for _ in '0'*n))