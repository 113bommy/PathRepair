a=input()
def decide(a):
	def loop(x,b):
		if b[0]=="H" or b[0]=="Q" or b[0]=="9":
			return "YES"
		elif len(b)>1:
			return loop(x+1,b[1:])
		else:
			return "NO"
	return loop(0,a)
print (decide(a))