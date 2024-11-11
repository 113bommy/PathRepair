n = int(input())

array = list(map(int, input().split()))
quantidadeDeNum = {}

for i in range(0, n):
	if array[i] in quantidadeDeNum:
		quantidadeDeNum[array[i]] += 1
	else:
		quantidadeDeNum[array[i]] = 1
da = True
for x in quantidadeDeNum.values():
	if (x >= n / 2 + 1):
		da = False
		break

if (da or n == 1):
	print("YES")

else:
	print("NO")