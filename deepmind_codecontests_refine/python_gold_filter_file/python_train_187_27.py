n = int(input())
f = [int(input().replace(' ',''),2) for i in range(n)]
p = [list(map(int,input().split())) for i in range(n)]
prof = - 10 ** 10
for i in range(1,1 <<10):
	prof1 = 0
	for j,time in enumerate(f):
		same = bin(i & time).count('1')
		prof1 += p[j][same]
	prof = max(prof,prof1)
print(prof)
