from sys import stdin,stdout
input = stdin.readline
def write(n,sep="\n"):
	stdout.write(str(n))
	stdout.write(sep)
def gil():
	return list(map(int, input().split()))
	
for _t in range(int(input())):
    n = int(input())
    for i in range(n, 0,-1):
        print(i, end = " ")
    print()

