import sys
 
q = int(input())
n, s = [], []
for i in range(q):
	n.append(int(input()))
	s.append(int(input()))
for i in range(q):
	if n[i]==2 and s[i]//10>=s[i]%10:
		print('NO')
	else:
		k = s[i]%pow(10, n[i]-1)
		print('YES')
		print(2)
		print(str(s[i]-k)[0], k)	