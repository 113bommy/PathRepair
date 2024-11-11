n = int(input())
s = input()

a = [len(x)+1 for x in s.split('1')]

if n == 0:
    print(sum(x *(x-1) // 2 for x in a))
else:
    print(sum(a * b for (a, b) in zip(a, a[n:])))
	 	 	 		 	 		 			 	  	 					