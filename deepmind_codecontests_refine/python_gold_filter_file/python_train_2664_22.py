n = int(input())
s = "ROYGBIV"
#s1 = s[3:]
rem = n % 7 
q = n // 7
s2 = '' 
if n <= 7:
	print(s[:n])
else:
	if rem <= 4:
		s2 += q*(s)
		s2 += s[3:3 + rem]
	else:
		s2 += q*(s)
		s2 += s[:rem]
	print(s2)