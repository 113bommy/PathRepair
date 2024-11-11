n,k=map(int,input().split())
print(['Yes','No'][any((n+1)%i for i in range(2,k+1))])