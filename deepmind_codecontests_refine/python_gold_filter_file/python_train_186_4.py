from itertools import*
N,K,Q,*A=map(int,open(0).read().split())
s=sorted
print(min((s(sum((v[:max(0,-~len(v)-K)]for v in(k*s(v)for k,v in groupby(A,lambda a:a>=Y))),[]))[Q-1:]or[2e9])[0]-Y for Y in A))