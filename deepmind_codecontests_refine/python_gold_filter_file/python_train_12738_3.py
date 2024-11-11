n=int(input())
if n%2: print(-1)
else: print(' '.join(list(map(str,list(range(1,n+1))))[::-1]))