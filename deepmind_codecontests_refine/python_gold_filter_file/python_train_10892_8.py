def sol(v,l):	
	a=0
	b=0
	for x in range(0,l):
		if v[x]=='U':
			a+=1
		if v[x]=='D':
			a-=1
		if v[x]=='L':
			b-=1
		if v[x]=='R':
			b+=1	
	return (abs(a)+abs(b))
	
def main():
	la=int(input(""))
	n=input("")	
	print(la-sol(n,la))


if __name__ == '__main__':
	main()