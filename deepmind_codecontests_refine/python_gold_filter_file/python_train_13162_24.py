a = list(map(int, input().split()))
b = list(map(int, input().split()))

b.sort(reverse=True)

x = sum(b[1:])

if (a[1] < x):
    print("NO")
else:
    print("YES")


	  	 		 	 		 		  		  		   	 	