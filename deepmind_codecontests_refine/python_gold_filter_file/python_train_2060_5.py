n=input()
keta=[0,0]
for i in range(len(n)):
	keta.append(int(n[i]))
ans=0
for i in range(len(keta)-1):
	if keta[-i-2]>=5:
		if keta[-i-1]>=5:
			ans+=10-keta[-i-1]
			keta[-i-2]+=1
		else:
			ans+=keta[-i-1]
	else:
		if keta[-i-1]>=6:
			ans+=10-keta[-i-1]
			keta[-i-2]+=1
		else:
			ans+=keta[-i-1]
print(ans)