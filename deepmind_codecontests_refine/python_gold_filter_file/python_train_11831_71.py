s=input()
res=0
for m in s:
	if m in ['1','3','5','7','9']:
		res+=1
	elif m in ['a', 'e', 'i', 'o','u']:
		res+=1
print(res)