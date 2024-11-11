import heapq as h;I=lambda:list(map(int,input().split()));n,k=I();z=[i*2+1for i in range(n)];s=sorted([I()for _ in[0]*n],key=lambda x:-x[1]);q=[];v=A=0;l=[0]*-~n
for a in s[:k]:
 if l[a[0]]:h.heappush(q,a[1])
 else:A+=z[v];v+=1
 l[a[0]]=1;A+=a[1]
T=A
for a in s[k:]:
 if not q:break
 if l[a[0]]^1:l[a[0]]=1;t=h.heappop(q);T=T-t+a[1]+z[v];v+=1;A=max(A,T)
print(A)