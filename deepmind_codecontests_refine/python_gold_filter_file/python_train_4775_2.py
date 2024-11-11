import array;R=range;L=input;T=[0]*28;N=int(L());S=[[ord(C)-95 for C in L()]for _ in[0]*N];U=N*26**2*array.array('i',[0]);V=N*[0];Q=int(L())
for X in S:
	P=0
	for C in X:
		if T[P+C]==0:T[P+C]=len(T);T+=[0]*28
		T[P]+=1;P=T[P+C]
	T[P]+=1;T[P+1]=1
while N:
	N-=1;P=0
	for C in S[N]:
		for A in R(26):X=T[P+A+2];U[676*N+26*A+C-2]+=T[X]*(X and A!=C-2)
		V[N]+=T[P+1];P=T[P+C]
while Q:
	K,P=L().split();K=int(K)-1;P=[ord(C)-97 for C in P];X=1+V[K]
	for A in R(26):
		for B in R(A+1,26):X+=U[676*K+26*P[A]+P[B]]
	print(X);Q-=1