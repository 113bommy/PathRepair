
from math import ceil, log
d=dict()


def pf(n):
	i=2
	while(i*i<= n):
		while(n%i==0):
			d[i]=d.get(i,0)+1
			n=n//i
		i+=1
	if(n!=1):
		d[n]=d.get(n,0)+1

n=int(input())
if(n==1):
    print(1,0)
else:
    pf(n)		
    m= max(d.values())
    steps=0
    flag=False
    for i in d.values():
        if( i!=m):
            steps+=1
            flag=True
            break

    x= log(m,2)

    if(flag or x.is_integer()):
        steps+=ceil(x)
    else:
        steps+=ceil(x)+1

    ans=1
    for i in d.keys():
        ans = ans  * i
    print(ans,steps)
