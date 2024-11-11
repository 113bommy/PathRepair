s = input()
st = set()
mp = dict()
for i in s:
	if i in st:
		mp[i]+=1
	else:
		mp[i] = 1
		st.add(i)
od,ev = 0,0
for i in st:
	if mp[i]%2:
		od+=1
	else:
		ev+=1
if od%2==1 or od==0:
	print("First")
else:
	print("Second")
