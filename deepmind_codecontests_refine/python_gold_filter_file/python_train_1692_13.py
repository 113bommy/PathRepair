import math 
  

def isPowerOfTwo(n): 
    if (n == 0): 
        return False
    while (n != 1): 
            if (n % 2 != 0): 
                return False
            n = n // 2
              
    return True
def find_power(n):
	count=0
	while(n>1):
		count+=1
		n=n//2

	return count;
for i in range(int(input())):
	a,b=map(int,input().split())
	x=max(a,b)
	y=min(a,b)
	
	if(x%y==0):
		z=x//y
		if( isPowerOfTwo(z)):
			power=find_power(z)
			ans=0
			while(power>0):
				if(power>2):
					ans+=1
					power-=3
				elif(power>1):
					ans+=1
					power-=2
				else:
					ans+=1
					power-=1
				
			print(ans)
		else:
			print(-1)
	else:
		print(-1)
	