N,K,*x =map(int,open(0).read().split())
print(sum(2*[min(i,K-i) for i in x]))
