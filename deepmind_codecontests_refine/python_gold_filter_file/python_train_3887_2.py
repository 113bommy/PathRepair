n=int(input())
coin=[int(x) for x in input().split()]
a=0
for i in range(len(coin)):
    a+=coin[i]
b=0
ncount=-1
coin.sort()
while b<=(a-b):
    b+=coin[ncount]
    ncount-=1
print(-1-ncount)