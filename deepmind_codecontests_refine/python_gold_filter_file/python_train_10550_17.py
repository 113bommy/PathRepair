a=set([i*(i+1)/2 for i in range(1,50000)])
n=int(input())
print(["NO","YES"][any(n-t in a for t in a)])