x,t,a,b,c,d=map(int,input().split())
R=range(t)
y=x==0
for i in R:
	if x==a-c*i or x==b-d*i:y=1
	for j in R:y|=x==a+b-c*i-d*j
print(['NO','YES'][y])