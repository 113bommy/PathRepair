Big=10**9+7
_=list(map(int,input().split(" ")))
N=_[0]
K=_[1]
gcd_list=[0 for _ in range(K)]
for i in range(K):
  s=K-i-1
  gcd_list[s]=(pow(K//(K-i), N, Big)-(sum(gcd_list[2*s+1::s+1]))%Big)%Big
answer=[(x+1)*gcd_list[x]%Big for x in range(K)]
print(sum(answer)%Big)