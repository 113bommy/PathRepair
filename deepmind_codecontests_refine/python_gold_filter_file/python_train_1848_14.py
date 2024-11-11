if __name__=="__main__":
	k = int(input())
	dic = {}
	for i in range(k):
		n = int(input())
		a = list(map(int,input().split()))
		s = sum(a)
		for xi, x in enumerate(a):
			s2 = s-x
			
			if s2 in dic and dic[s2][0]!=i+1:
				print("YES")
				print(i+1,xi+1)
				print(*dic[s2])
				exit()
			else:
				dic[s2]=(i+1, xi+1)
print("NO")