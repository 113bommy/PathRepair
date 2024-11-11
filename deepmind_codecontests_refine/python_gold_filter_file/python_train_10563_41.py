n, m = [int(x) for x in input().split()]
dic = {}

for i in range(m):
	fir, sec = input().split()
	if len(fir) > len(sec): dic[fir] = sec

li = input().split()

for i in range(len(li)):
	if li[i] in dic: li[i] = dic[li[i]]
	
print(' '.join(li))

