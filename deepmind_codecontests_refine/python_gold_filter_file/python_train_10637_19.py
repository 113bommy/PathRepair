n=int(input())
a=[int('0'.join(x))for x in input().split()]
print(11*n*sum(a)%998244353)