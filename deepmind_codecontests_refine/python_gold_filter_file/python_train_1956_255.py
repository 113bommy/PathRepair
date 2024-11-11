#C
n,k=map(int,input().split())
s=n%k
print(min(s,abs(s-k)))