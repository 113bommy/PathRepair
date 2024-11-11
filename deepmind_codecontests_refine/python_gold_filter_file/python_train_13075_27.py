n, m = map(int, input().strip().split())
s=list(input())
t=list(input())

diff = 999999999
diff_list = []
for i in range(0, len(t)-len(s) + 1):
	# print(t[i:i+len(s)])
	res=0
	rl=[] 
	for j in range(0, len(s)):
		if s[j]!=t[i:i+len(s)][j]:
			res+=1
			rl.append(j+1)
	# print(res, rl)
	if res<diff:
		diff = res
		diff_list=[a for a in rl]
# print(diff, diff_list)
print(diff)
if diff!=0: 
	print(*diff_list)