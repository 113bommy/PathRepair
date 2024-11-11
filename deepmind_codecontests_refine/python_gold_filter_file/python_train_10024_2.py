n=int(input());s=list(map(int,input().split()));a,b=s.index(max(s)),s[::-1].index(min(s))
print(a+b-(n-1-b<a))