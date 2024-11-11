N,M,K=list(map(int,input().split()))
root=[i for i in range(N)]
height=[1 for i in range(N)]
l=[set() for i in range(N)]
mem=[0]*N
def find(n):
   f=n
   while n != root[n]:
      n=root[n]
   root[f]=n
   return n
def union(a,b):
   A=find(a)
   B=find(b)
   if A==B:
      return
   elif height[A]<height[B]:
      height[B]+=height[A]
      height[A]=0
      root[A]=B
   else:
      root[B]=A
      height[A]+=height[B]
      height[B]=0
def same(a,b):
   A=find(a)
   B=find(b)
   if A==B:
      l[a].add(b)
      l[b].add(a)
for i in range(M):
   a,b=list(map(int,input().split()))
   a-=1;b-=1
   l[a].add(b)
   l[b].add(a)
   union(a,b)
for j in range(K):
   a,b=list(map(int,input().split()))
   a-=1;b-=1
   same(a,b)
for i in range(N):
   print(height[find(i)]-len(l[i])-1,end=" ")
