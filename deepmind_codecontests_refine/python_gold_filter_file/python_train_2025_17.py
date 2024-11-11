while True:
	try:	
		def solution(n, a):
			incr = True
			cunt = 0
			for i in range(1, n, 1):
				if a[i] < a[i-1]:
					incr = False
					cunt += 1
			if incr:
				print(0)
			else:
				prev = 10**6
				i, lan = n-1, 0
				while a[i] <= prev :
					lan += 1
					prev = a[i]
					i -= 1
				if cunt >= 2 or a[-1] > a[0]:print(-1)
				else:print(lan)		
		
		def read():
			n = int(input())
			a= list(map(int, input().split()))
			solution(n, a)
			
		if __name__ == "__main__":
			read()
	except EOFError:
		break