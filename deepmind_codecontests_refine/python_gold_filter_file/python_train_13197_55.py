N=int(input())
l=sorted(list(map(int,input().split())))
l.reverse()
s=l[0]+N%2*l[N//2]
for i in range(N//2-1):
  s+=l[i+1]*2
print(s)