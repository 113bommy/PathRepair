
def toggle(s, arr,n, k):
	for i in range(n):
		z =  (k - arr[i][1])
		if z >= 0  and z % arr[i][0] == 0:
			s[i] = '1' if s[i] == '0' else '0'
	return s


n= int(input())
s = list(input())
arr = []
for _ in range(n):
	arr.append(list(map(int, input().split())))
mx  = s.count('1')

if mx== n:
	print(n)
else:
	for k in range(n* 25):
		s = toggle(s, arr, n, k+1)
		mx = max(mx, s.count('1'))
	
	print(mx)
