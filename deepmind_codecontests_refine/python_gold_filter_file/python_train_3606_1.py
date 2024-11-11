n = int(input().strip())
arr = list(map(int, input().strip().split()))
arr.sort(reverse=True)
for i in arr:
	if i < 0:
		print(i)
		break
	sq = i**.5
	if sq != int(sq):
		print(i)
		break
