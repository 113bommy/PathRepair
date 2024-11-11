length = input()
nums = input().split(" ")

numdict = {}
for i, num in enumerate(nums):
	if num not in numdict:
		numdict[str(num)] = 1
	else:
		numdict[str(num)] += 1

ret = 0
for k,v in numdict.items():
	if int(k) > int(v):
		ret += int(v) 
	else:
		ret += int(v) - int(k)

print(ret)