'''
INPUT SHORTCUTS
N, K = map(int,input().split())
N ,A,B = map(int,input().split())
string = str(input())
arr = list(map(int,input().split()))
N = int(input())
'''


def main():
	# flag = True
	n,a,b,c,d = map(int,input().split())
	# for i in range(c-d,c+d+1):
	if ((a+b)*n)<(c-d) or ((a-b)*n)>(c+d):
		return True
	else:
		return False
	
t= int(input())
while t:
	flag = main()
	if flag:
		print("No")
	else:
		print("Yes")
	t-=1