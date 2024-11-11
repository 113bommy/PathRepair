import sys
input = sys.stdin.readline
 
############ ---- Input Functions ---- #######Start#####
def inp():
	return(int(input()))
def inlt():
	return(list(map(int,input().split())))
def insr():
	s = input()
	return((s[:len(s) - 1]))
def invr():
	return(map(int,input().split()))
 ############ ---- Input Functions ---- #######End#####   
def main():
	q = inp()
	for i in range(0,q):
		[n,m] = inlt()
		limit_L = m
		limit_h = m
		curr_time = 0
		flag = 1
		for j in range(0,n):
			[t,l,h] = inlt()
			limit_L = limit_L - (t-curr_time)
			limit_h = limit_h + (t-curr_time)
			if limit_L > h or limit_h <  l:
				flag = 0
			curr_time = t
			limit_L = max(limit_L,l) 
			limit_h = min(limit_h,h)
		if flag == 1:
			print("YES")
		else:
			print("NO")
	return
if __name__== "__main__":
  main()