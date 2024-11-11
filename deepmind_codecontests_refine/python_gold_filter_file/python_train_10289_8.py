def next(x):
    return chr(ord(x)+1)

import sys

A=set([chr(ord("a")+k) for k in range(26)])
S=input()

if len(S)!=26:
    u=min(A-set(S))
    print(S+u)
    exit()

p=-1

for i in range(25):
    if S[i]<S[i+1]:
        p=i

if p==-1:
    print(-1)
else:
    T=S[:p]
    a=next(S[p])

    while a in T:
        a=next(a)
    print(T+a)
