import sys
#input = sys.stdin.readline
input = sys.stdin.buffer.readline

# mod=10**9+7
# rstrip().decode('utf-8')
# map(int,input().split())
# import numpy as np


def main():
	h,w=map(int,input().split())
	A=[list(map(int,input().split())) for _ in range(h)]
	B=[list(map(int,input().split())) for _ in range(h)]
	C=[[0]*w for _ in range(h)]
	for i in range(h):
		for j in range(w):
			C[i][j]=abs(A[i][j]-B[i][j])
	D=[[0]*w for _ in range(h)]
	D[0][0]=(1<<C[0][0]+5000)|(1>>C[0][0]+5000)
	for i in range(h):
		for j in range(w):
			if i>0:
				D[i][j]=D[i][j]|(D[i-1][j]<<C[i][j])|(D[i-1][j]>>C[i][j])
			if j>0:
				D[i][j] = D[i][j]|(D[i][j-1] << C[i][j]) | (D[i][j-1] >> C[i][j])

	val=D[-1][-1]
	ans=5000

	for i in range(10000):
		if val>>i&1:
			ans=min(ans,abs(i-5000))
	print(ans)

if __name__ == "__main__":
	main()
