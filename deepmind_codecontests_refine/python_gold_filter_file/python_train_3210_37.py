a,b,k=map(int,input().split())
s=range(a,b+1)
for i in sorted(set(s[:k])|set(s[-k:])):
    print(i)