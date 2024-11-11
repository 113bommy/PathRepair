def swap(list, pos1, pos2):
	list[pos1], list[pos2] = list[pos2], list[pos1] 
	return list

t=int(input())
for i in range(t):
	n=list(input())
	if n.count(n[0]) == len(n):
		print(-1)
	elif len(n) == 1:
		print(-1)
	else:
		for j in range(len(n)-1):
			if n[j]!=n[j+1] and n[j]==n[len(n)-j-1] and j!=len(n)-j-1:
				swap(n,j,j+1)
				#print(j,j+1)
		print(*n,sep="")