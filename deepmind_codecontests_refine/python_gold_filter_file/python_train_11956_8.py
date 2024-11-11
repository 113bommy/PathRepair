N=int(input())
K=int(input())
def ans(s):
  n=int(s)
  return 2*min(K-n,n)
x=list(map(ans,input().split()))
print(sum(x))

