s = input()

t = int(input())

for i in range(t):
	
	l,r,k = map(int,input().split())

	temp = s[l-1:r]

	if k > (r-l+1):
		k = k%(r-l+1)

	temp = temp[-k:] + temp[:-k]

	# print(temp)

	s = s[:l-1] + temp + s[r:]

	# print(s)

print(s)