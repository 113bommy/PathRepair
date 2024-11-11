def main():
	n = int(input())
	outpos = int(input())		
	
	even ={'ini1':[1,2,0],
		   'ini2':[2,0,1],
		   'ini3':[0,1,2]}
		
	odd = {'ini1':[1,0,2],
			'ini2':[2,1,0],
			'ini3':[0,2,1]}
		
	if n%2 == 0:			
		if n%6 == 2:
			print(even['ini1'][outpos])
		elif n%6 == 4:
			print(even['ini2'][outpos])
		elif n%6 == 0:
			print(even['ini3'][outpos])
	else:
		if n%6 == 5:
			print(odd['ini3'][outpos])
		elif n%6 == 3:
			print(odd['ini2'][outpos])
		elif n%6 == 7:
			print(odd['ini1'][outpos])
		else:
			print(odd['ini1'][outpos])	

if __name__=="__main__":
	main()
