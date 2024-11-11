spins = ["v","<","^",">"]
spinner = list(map(str,input().split()))
n = int(input())

if n%2 == 0:
	print("undefined")
elif (spins.index(spinner[0])+n)%4 == spins.index(spinner[1]):
	print("cw")
else:
	print("ccw")