import itertools
def erat2( ):
    D = {  }
    yield 2
    for q in itertools.islice(itertools.count(3), 0, None, 2):
        p = D.pop(q, None)
        if p is None:
            D[q*q] = q
            yield q
        else:
            x = p + q
            while x in D or not (x&1):
                x += p
            D[x] = p
def get_primes_erat(n):
    return list(itertools.takewhile(lambda p: p<n, erat2()))
n=int(input())
x=get_primes_erat(n+1)
a=[]
for i in x:
    N=1
    while i**N<=n:
        a.append(i**N)
        N+=1
print(len(a))
for i in a:
    print(i,end=' ')
