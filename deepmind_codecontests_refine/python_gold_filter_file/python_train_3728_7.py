X,Y,Z,K=map(int,input().split())
A=[int(x) for x in input().split()]
A.sort(reverse=True)
B=[int(x) for x in input().split()]
B.sort(reverse=True)
C=[int(x) for x in input().split()]
C.sort(reverse=True)
D=[a+b for a in A for b in B]
D.sort(reverse=True)
D=D[:3000]
E=[ab+c for ab in D for c in C]
E.sort(reverse=True)
for i in range(K):
  print(E[i])
