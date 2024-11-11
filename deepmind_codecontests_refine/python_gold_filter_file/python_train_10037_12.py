# import sys
# sys.stdin = open("F:\\Scripts\\input","r")
# sys.stdout = open("F:\\Scripts\\output","w")


MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))

s = input()
res = ''
d = []
n = len(s)
if n < 3:
	print(s)
else:
	res += s[:3]
	i = 3
	j = 2
	if res[j] == res[j-1] and res[j-1]==res[j-2]:
		res = res[:j]
		j -= 1
	while i < n:
		res += s[i]
		i += 1
		# while i < n and res[-1] == s[i]:
		# 	i += 1
		j += 1
		if j >= 2 and res[j] == res[j-1] and res[j-1]==res[j-2]:
			res = res[:j]
			j -= 1
		if j >= 3 and res[j] == res[j-1] and res[j-2] == res[j-3]:
			res = res[:j]
			j -= 1	
	print(''.join(res))
