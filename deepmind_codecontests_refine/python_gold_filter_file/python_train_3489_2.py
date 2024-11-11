import sys
import itertools
def s(p1,p2,p3):
	return (p1[0]-p3[0])*(p2[1]-p3[1])-(p2[0]-p3[0])*(p1[1]-p3[1])
e = 1e-22
def inTri(p, p1, p2, p3):
	l = [p1,p2,p3]
	for i in itertools.permutations(l):
		if abs(t(i[0],i[1])-t(i[0],p))<=e and min(i[0][0],i[1][0])<=p[0]<=max(i[0][0],i[1][0]) and min(i[0][1],i[1][1])<=p[1]<=max(i[0][1],i[1][1]):
			return True
	return (s(p,p1,p2)<=0)==(s(p,p2,p3)<=0) and (s(p,p2,p3)<=0)==(s(p,p3,p1)<=0)

def t(p1, p2):
	if p2[0] == p1[0]: return 2e9
	return (p2[1]-p1[1])/(p2[0]-p1[0])
n = int(input())
l = []
n1 = 0
n2 = 1
n3 = -1
for i in range(n):
	p = tuple(map(int,input().split()))
	l.append(p)
for i in range(2,n):
	if t(l[n1],l[n2]) == t(l[n1],l[i]) and (l[n1][0]-l[n2][0])**2+(l[n1][1]-l[n2][1])**2 > (l[n1][0]-l[i][0])**2+(l[n1][1]-l[i][1])**2:
		n2 = i
for i in range(n):
	if i==n1 or i==n2: continue
	if abs(t(l[i],l[n1])-t(l[i],l[n2]))<=e:
		continue
	if n3<0:
		n3=i
		continue
	if inTri(l[i], l[n1],l[n2],l[n3]):
		n3 = i
		continue
print(n1+1,n2+1,n3+1)