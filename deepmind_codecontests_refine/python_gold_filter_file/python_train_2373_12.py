N=int(input())
d,m=divmod(N,100)
print(['0','1'][m<=(d*5)])