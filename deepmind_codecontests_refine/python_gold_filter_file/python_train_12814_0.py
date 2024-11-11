
n = int(input())
s = input()
t = input()

res = []
flag = 0
for i in range(n):
	if s[i] == t[i]:
		continue
	k = s[i:]
	# print(k,i)
	idx = k.find(t[i])
	# print(i,idx)
	if(idx == -1):
		flag = 1
		break
	idx += i
	s = s[:i]+s[idx]+s[i:idx]+s[idx+1:]
	dum = []
	for j in range(i,idx):
		dum.append(j+1)
	dum.reverse()
	res.extend(dum)

if flag == 1:
	print("-1")
else:
	print(len(res))
	for i in res:
		print(i,end=" ")