t = int(input())
lst = list()
odd =0 
even = 0
while(t):
    t = t-1
    str1 = input()
    n,x = map(int,str1.split())
    str1 = input()
    lst = list(map(int,str1.split()))
    for i in range(0,n):
        if lst[i] % 2 == 0:
            even = even +1
        elif lst[i]%2 != 0:
            odd = odd+1
    if odd ==0 :
    	print("No")
    else:
    	if x%2==0:
    		if odd%2==0:
    			c=odd-1
    		else:
    			c=odd
    		if c+even >=x and even!=0:
    			print("Yes")
    		else:
    			print("No")
    	if x%2!=0:
    		if even%2==0:
    			c=even
    		else:
    			c=even-1
    		if (x-c)<=odd:
    			print("Yes")
    		else:
    			print("No")
    odd = 0
    even = 0