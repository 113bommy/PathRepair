r = lambda: map(int,input().split())
n, l = r()
c = sorted(list(r()))
print (sum(x*max(l-i,1) for i,x in enumerate(c)))