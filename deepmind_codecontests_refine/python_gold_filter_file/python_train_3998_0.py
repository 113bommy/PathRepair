n=int(input());l=list(map(int,input().split()));t=0
for i in range(n):
	for j in range(n):
		for k in range(n):
			if i==j or j==k or k==i:continue
			if l[i]+l[j]==l[k]:print(k+1,i+1,j+1);t=1;break
		if t:break
	if t:break
else:print(-1)