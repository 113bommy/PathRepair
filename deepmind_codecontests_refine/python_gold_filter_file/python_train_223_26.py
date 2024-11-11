T = int(input())
k=1
def XOR(a,b,n):
	if n%3==0: return a
	elif n%3==1: return b
	else: return a^b
while k<=T:
	vvod = input()
	c = [int(x) for x in vvod.split()]
	print(XOR(c[0],c[1],c[2]))
	k += 1