import sys
sys.setrecursionlimit(100000)
recipe = sys.stdin.readline().strip()
n = [int(x) for x in sys.stdin.readline().strip().split()]
p = [int(x) for x in sys.stdin.readline().strip().split()]
r = int(sys.stdin.readline())
d  = [0,0,0]
dic = {"B":0,"S":1,"C":2}
for i in recipe:
	d[dic[i]]+=1
# ma = -10**13
# index = -1
# for i in range(3):
# 	if d[i]!=0 and ma<n[i]/d[i]:
# 		ma = n[i]/d[i]
# 		index = i
# req = (d[index]-n[index]%d[index])%d[index]
# ma = (n[index]+req)//d[index]
# index = -1
# for i in range(1,ma+1):
# 	for j in range(3):
# 		if d[j]*i>n[j]:
# 			if r-(d[j]*i-n[j])*p[j]>=0:
# 				r=r-(d[j]*i-n[j])*p[j]
# 				n[j]=i*d[j]

high = r+n[0]*p[0]+n[1]*p[1]+n[2]*p[2]
low = 0

while high>=low:
	mid = (high+low)//2
	su = 0
	for j in range(3):
		su+=(d[j]*mid-n[j])*p[j] if mid*d[j]>n[j] else 0

	if r-su<0:
		high=mid-1
	if r-su>0:
		low = mid+1
	if r==su or mid==0 or mid==low and mid == high:
		break
	

if r-su<0:
	print(mid-1)
else:
	print(mid)

# su = d[0]*p[0]+d[1]*p[1]+d[2]*p[2]
# tot = r//su+ma
# print(tot)


