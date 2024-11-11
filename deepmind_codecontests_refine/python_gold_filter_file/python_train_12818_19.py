import bisect
def main():
	n,x,y = map(int,input().split())
	a = list(map(int,input().split()))
	if x>y:
		print(len(a))
	elif x<=y:
		a.sort()
		index = bisect.bisect_right(a,x)
		if index==0:
			print(0)
			return
		print(((index+1)//2))



main()