import sys 

# sys.stdin=open("pyinput.txt", 'r')
# sys.stdout=open("pyoutput.txt", 'w')

def scan(TYPE_1, TYPE_2=0):
	if(TYPE_1==int):
		return map(int, sys.stdin.readline().strip().split())
	elif(TYPE_1==float):
		return map(float, sys.stdin.readline().strip().split())
	elif(TYPE_1==list and TYPE_2==float):
		return list(map(float, sys.stdin.readline().strip().split()))
	elif(TYPE_1==list and TYPE_2==int):
		return list(map(int, sys.stdin.readline().strip().split()))
	elif(TYPE_1==str):
		return sys.stdin.readline().strip()
	else: print("ERROR!!!!") 



def main():
	
	n, m=scan(int)
	s=[]
	a=[]

	for i in range(n): s.append(scan(str))
	x=scan(list, int)

	for i in range(m):
		a.append(s[x[i]-1])

	l=len(a[0])
	flag=1
	for i in range(1, m):
		if(l!=len(a[i])): flag=0

	if(flag==0):
		print('No')
		return

	ans=''
	for i in range(l):
		k=a[0][i]
		for j in range(1, m):
			if(a[j][i]!=k):
				ans+='?'
				break
		if(len(ans)!=i+1): ans+=k

	k=[]
	for i in range(n):
		if(len(s[i])!=l): continue
		flag=True
		for j in range(l):
			if(s[i][j]!=ans[j] and ans[j]!='?'):
				flag=False
				break
		if(flag): k.append(i+1)

	if(k==x): print('Yes', ans, sep='\n')
	else: print('No')


main()