s=input()
ans="CODEFESTIVAL2016"
anss=0
for i in range(16):
	if s[i]!=ans[i]:
		anss+=1
print(anss)