S=input()
n=len(S)
ans=0
 
for paint in range(2**(n-1)):
	temp_S=S[0]
 
	for i in range(n-1):
		if (paint>>i)&1==1:
			temp_S+="+"
		temp_S+=S[i+1]
 
	ans+=sum(map(int, temp_S.split("+")))
print(ans)