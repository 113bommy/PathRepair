# -*- coding: utf-8 -*-

import sys
sys.setrecursionlimit(10**6)

def search(values,hp,vp,item):
	if not (0<=hp<len(values)): return
	if not (0<=vp<len(values[hp])): return
	if item!=values[hp][vp]: return
	values[hp][vp]=True
	for dh,dv in [[0,1],[0,-1],[1,0],[-1,0]]:
		search(values,hp+dh,vp+dv,item)
#	search(values,hp-1,vp,item)
#	search(values,hp+1,vp,item)
#	search(values,hp,vp-1,item)
#	search(values,hp,vp+1,item)

def solve(values):
	count,valid_items=0,set(['@','#','*'])
	for i in range(len(values)):
		for j in range(len(values[i])):
			if values[i][j] in valid_items:
				search(values,i,j,values[i][j])
				count+=1
	return count

def main():
	line = input().strip()
	while line!='0 0':
		H,W = list(map(int,line.split(' ')))
		values = list()
		for _ in range(H):
			values.append(list(input().strip()))
		print(solve(values))
		line = input().strip()

if __name__=='__main__':
	main()