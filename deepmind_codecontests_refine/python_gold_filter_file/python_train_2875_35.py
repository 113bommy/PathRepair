if __name__ == "__main__":
	n,k = map(int,input().split())
	if k==0 or (n-k)==0:
		print(0,0)
	elif k>=n//2:
		print(1,n-k)
	else:
		if 2*k>(n-k):
			print(1,n-k)
		else:
			print(1,k*2)
			
