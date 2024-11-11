def main():
	t = int(input())
	a = [int(x) for x in input().split()]
	p2 = [2**i for i in range(32)]
	dic = {}
	for e in a:
		dic[e] = 1
	a.sort()
	ans = []
	for i in a:
		for j in p2:
			if dic.get(i+j):
				if not ans:
					ans = [i,i+j]
				if dic.get(i+j*2):
					print(3)
					print(i,i+j,i+j*2)
					return
	if ans:
		print(2)
		print(ans[0],ans[1])
	else:
		print(1)
		print(a[0])
if __name__ == '__main__':
	main()
