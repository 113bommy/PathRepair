# Problem: C1. Binary Table (Easy Version)
# Contest: Codeforces - Codeforces Round #684 (Div. 2)
# URL: https://codeforces.com/contest/1440/problem/C1
# Memory Limit: 256 MB
# Time Limit: 1000 ms
# 
# KAPOOR'S

from sys import stdin, stdout 

def INI():
	return int(stdin.readline())
	
def INL():
	return [int(_) for _ in stdin.readline().split()]
	
def INS():
	return stdin.readline()

def MOD():
    return pow(10,9)+7
	
def OPS(ans):
	stdout.write(str(ans)+"\n")
	
def OPL(ans):
	[stdout.write(str(_)+" ") for _ in ans]
	stdout.write("\n")

def one():	
	if T[0]=="1":
		ANS.extend([I[0],I[1],I[2]])
		ANS.extend([I[0],I[2],I[3]])
		ANS.extend([I[0],I[1],I[3]])
	elif T[1]=="1":
		ANS.extend([I[0],I[1],I[2]])
		ANS.extend([I[2],I[1],I[3]])
		ANS.extend([I[3],I[1],I[0]])
	elif T[2]=="1":
		ANS.extend([I[0],I[2],I[1]])
		ANS.extend([I[1],I[2],I[3]])
		ANS.extend([I[3],I[2],I[0]])
	else:
		ANS.extend([I[0],I[3],I[1]])
		ANS.extend([I[1],I[3],I[2]])
		ANS.extend([I[2],I[3],I[0]])

def two():
	if T[0]=="1" and T[1]=="1":
		ANS.extend([I[0],I[2],I[3]])
		ANS.extend([I[1],I[2],I[3]])
	elif T[0]=="1" and T[2]=="1":
		ANS.extend([I[0],I[1],I[3]])
		ANS.extend([I[2],I[1],I[3]])
	elif T[0]=="1" and T[3]=="1":
		ANS.extend([I[0],I[1],I[2]])
		ANS.extend([I[3],I[1],I[2]])
	elif T[1]=="1" and T[2]=="1":
		ANS.extend([I[1],I[0],I[3]])
		ANS.extend([I[2],I[0],I[3]])
	elif T[1]=="1" and T[3]=="1":
		ANS.extend([I[1],I[0],I[2]])
		ANS.extend([I[3],I[0],I[2]])
	elif T[2]=="1" and T[3]=="1":
		ANS.extend([I[2],I[0],I[1]])
		ANS.extend([I[3],I[0],I[1]])
def three():
	if T[0]=="0":
		ANS.extend([I[1],I[2],I[3]])
	elif T[1]=="0":
		ANS.extend([I[0],I[2],I[3]])
	elif T[2]=="0":
		ANS.extend([I[0],I[1],I[3]])
	else:
		ANS.extend([I[0],I[1],I[2]])
		
def four():
	ANS.extend([I[1],I[2],I[3]])
	ANS.extend([I[0],I[1],I[2]])
	ANS.extend([I[0],I[2],I[3]])
	ANS.extend([I[0],I[1],I[3]])
	
if __name__=="__main__":
	for _ in range(INI()):
		n,m=INL()
		X=[]
		for _ in range(n):
			x=input()
			X.append(list(x))
		ANS=[]
		ans=0
		
		for _ in range(n-1):
			for __ in range(m-1):
				T=[X[_][__],X[_][__+1],X[_+1][__],X[_+1][__+1]]
				I=[[_,__],[_,__+1],[_+1,__],[_+1,__+1]]
				if T.count("1")==1:
					one()
				elif T.count("1")==2:
					two()
				elif T.count("1")==3:
					three()
				elif T.count("1")==4:
					four()
				for i in I:
					X[i[0]][i[1]]="0"
				
		
		ans=(len(ANS)+2)//3
		print(ans)
		for _ in range(0,len(ANS),3):
			for __ in range(3):
				print(ANS[_+__][0]+1,ANS[_+__][1]+1,end=" ")
			print()