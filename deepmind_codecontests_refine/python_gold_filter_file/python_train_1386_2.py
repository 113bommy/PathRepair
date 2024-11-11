if __name__ == "__main__":
	n = int(input())
	arr = list(map(int, input().split()))
	
	d = {}
	flag = 0
	
	for i in range(n):
		for j in range(i+1, n):
			s = arr[i] + arr[j]
		
			if( s not in d ):
				d[s] = (i,j)
			else:
				if( d[s][0]==i or d[s][1]==i or d[s][0]==j or d[s][1]==j ):
					continue
				
				print( "YES" )
				print( d[s][0]+1, d[s][1]+1, i+1, j+1 )
				flag = 1
				break
		
		if( flag == 1 ):
			break
	
	if( flag == 0 ):
		print( "NO" )
			
