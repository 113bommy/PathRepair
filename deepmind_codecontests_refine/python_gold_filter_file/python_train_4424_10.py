a="CODEFORCES"
s=input()
f=0
for i in range(11):
	if a[:i]==s[:i] and a[i:]==s[-10+i:]:
		f=1
if a==s[:10]:
	f=1
if f==1:
	print("YES")
else:
	print("NO")