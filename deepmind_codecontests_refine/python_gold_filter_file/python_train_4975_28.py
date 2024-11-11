import sys
input = sys.stdin.buffer.readline


# mod=10**9+7
# rstrip().decode('utf-8')
# map(int,input().split())
# import numpy as np


from collections import deque
from collections import defaultdict


def main():
	N=int(input())
	M=N-1
	G = defaultdict(set)

	color = [0 for i in range(N + 1)]

	for _ in range(M):
		A, B = map(int, input().split())
		G[A].add(B)
		G[B].add(A)

	color[1] = 1
	que = deque([1])  # 始点を追加

	while len(que):
		p = que.popleft()  # 直近で追加したグラフの頂点を取得
		for q in list(G[p]):  # 結合しているグラフの頂点を参照
			if color[q] == 0:  # 塗られていないなら別の色で塗る
				color[q] = -color[p]
				que.append(q)


	b=[]
	w=[]
	for i in range(1,N+1):
		if color[i]==1:
			b.append(i)
		else:
			w.append(i)

	ans=[0]*(N+1)
	lim = ((N - 1) // 3)
	i=0
	if len(b)<len(w):
		for val in w:
			if i<=lim:
				ans[val]=3*i+1
				i+=1
			else:
				break
		w=w[i:]
	else:
		for val in b:
			if i<=lim:
				ans[val]=3*i+1
				i+=1
			else:
				break
		b=b[i:]


	lim = ((N - 2) // 3)
	i=0
	if len(b)<len(w):
		for val in w:
			if i<=lim:
				ans[val]=3*i+2
				i+=1
			else:
				break
		w=w[i:]
	else:
		for val in b:
			if i<=lim:
				ans[val]=3*i+2
				i+=1
			else:
				break
		b=b[i:]


	i=0
	for val in b:
		ans[val]=3*i+3
		i+=1
	for val in w:
		ans[val]=3*i+3
		i+=1




	print(*ans[1:])




if __name__ == "__main__":
	main()
