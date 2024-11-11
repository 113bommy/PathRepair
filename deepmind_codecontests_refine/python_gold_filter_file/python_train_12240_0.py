n, m, k = map(int,input().split())

print((k-1)//(2*m)+1,(k-1)%(2*m)//2+1,'L' if k%2  else 'R')