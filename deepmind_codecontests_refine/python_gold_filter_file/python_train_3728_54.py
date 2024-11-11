X,Y,Z,K=map(int,input().split())
A= list(map(int,input().split()))
B= list(map(int,input().split()))
C= list(map(int,input().split()))
AB=[0]*(X*Y)
t=0
for i in A:
 for j in B:
  AB[t]=i+j
  t+=1
AB.sort(reverse=True)
ABA=AB[0:min(K,X*Y)]
D=[0]*(Z*len(ABA))
t=0
for i in ABA:
 for j in C:
  D[t]=i+j
  t+=1
D.sort(reverse=True)
for i in range(K):
 print(D[i])
