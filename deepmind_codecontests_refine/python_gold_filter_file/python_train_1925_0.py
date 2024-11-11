number = int(input())
origin = list(input().split())
array = list(input().split())

positions = {}

pre = []
last = []

result = 0

for i in range(number):
	if origin[i] == array[i]:
		continue
	else:
		j = i + 1
		index = len(pre)
		for j in range(i+1, number):
			pre.insert(index,j+1)
			last.insert(index,j)
			if array[j] == origin[i]:
				break

		array[i+1: j+1] = array[i:j]
		result += j - i

print(result)
for i in range(len(pre)):
	print(str(last[i])+" "+str(pre[i]))
