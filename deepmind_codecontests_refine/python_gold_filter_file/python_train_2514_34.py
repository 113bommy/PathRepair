n = int(input())
num = list(map(int, list(input().strip())))
s = map(int, input().split())
dic = {digit:res for digit,res in enumerate(s,1)}
i = 0
for dig in num:
	if dic[dig] > dig:
		break
	else:
		i += 1
while i < n and dic[num[i]] >= num[i]:
	num[i] = dic[num[i]]
	i += 1
print(''.join(list(map(str, num))))
