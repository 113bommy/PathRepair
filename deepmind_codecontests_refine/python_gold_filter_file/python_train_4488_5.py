x,y=map(int,input().split())
a=list(map(str,input()))
b=list()
j=1
j=int(j)
for i in range(y-1):
    b.append(a.count(chr(ord('A')+j)))
    j=j+1
b.append(a.count('A'))
print(min(b)*y)
   	  		    	 	  			 	 	  	 			