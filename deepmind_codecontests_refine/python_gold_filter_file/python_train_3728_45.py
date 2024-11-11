import itertools

X, Y, Z, K = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]
 
list_ = [b+c for (b,c) in itertools.product(B, C)]
list_.sort(reverse=True)
 
list__ = [ab+c for (ab,c) in itertools.product(list_[:K], A)]
list__.sort(reverse=True)
for N in list__[:K]:
  print(N)