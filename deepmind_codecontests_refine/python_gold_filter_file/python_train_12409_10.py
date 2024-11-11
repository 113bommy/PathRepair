l,r = map(int, input().split())
result = -1
for i in range(l, r+1):
	li = list(str(i))
	if len(li) == len(set(li)):
		result = i
		break

print(result)
	