from sys import stdin,stdout
input = stdin.readline
def write(n,sep="\n"):
	stdout.write(str(n))
	stdout.write(sep)
def gil():
	return list(map(int, input().split()))
	
s = input()
t = input()
x = 0

for i in range(len(t)):
	if s[x] == t[i]:
		x += 1
print(x+1)
