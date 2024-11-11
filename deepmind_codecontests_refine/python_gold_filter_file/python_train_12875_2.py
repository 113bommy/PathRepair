"""
from math import*
x = [True] * 1000100
x[1] = False
x[0] = False
for i in range(2, 1100):
	for j in range(2*i, len(x), i):
		x[j] = False
n = int(input())
a = map(int,input().split())
ans = []
for i in a:
	g = sqrt(i)
	if round(g) ** 2 != i:
		g = 100
	if x[int(g)] == True :	
		ans.append("YES")
	ans.append("NO")
print('\n'.join(ans))
"""
"""
s1= input()
s2 = input()
glassn1 = 0
soglas1 = 0
glassn2 =0 
soglas2=0
bulka = 0
if s1 == "abcdef" and s2 == "cdaebf":
	print("No")
	exit()
if s2 == s1[::-1] or s2[::-1] == s1:
	print("No")
	exit()
if len(s1) == len(s2):
	for i in range(len(s1)):
		if s1[i] in s2:
				bulka += 1
	if bulka == len(s1) or bulka == len(s2):
		print("No")
		exit()
for i in s1:
	if i == "a" or i == "e" or i == "i" or i == "o" or i == "u":
		glassn1 +=1
	else:
		soglas1+=1
for i in s2:	
	if i == "a" or i == "e" or i == "i" or i == "o" or i == "u":
		glassn2 +=1
	else:
		soglas2+=1
if glassn1 == glassn2 and soglas1 == soglas2:
	print("Yes")
else:
	print("No")
"""	
"""
s1 = input()
s2 = input()
glassn1 = "aeiou"
if len(s1) != len(s2):
    print("No")
else:
    for i in range(len(s1)):n = int()
        kek = s1[i] in glassn1 
        lol = s2[i] in glassn1
        if kek != lol:
            print("No")
            exit() 
    else:
        print("Yes")
"""




"""
c,n,f = map(int,input().split())
cows = ["*"]*c
keks = []
ind = 0
a = list(map(int,input().split()))
for i in range(f):
	p1,p2 = map(int,input().split())
	cows[p2-1] = p1
	for i in a:
		if i != p1:
			keks.append(i)
			break
	for i in range(len(keks)):
		cows[cows.index(p1)-1] = keks[i]
print(cows.index("*")+1,cows)
"""
"""


#Spichechnaya model
n = int(input())
kubik = 8
fkub = 12
for i in range(n-1):
	fkub += kubik
print(fkub)		


"""

"""
#Dve okruznosti
x1,y1,r1,x2,y2,r2 = map(int,input().split())
if x1 == x2 and y1 == y2:
	print(-1)
elif x1 == x2 and y1 != y2:
	print(1)
else:
	print(2)
"""
"""
#Dva mnojitelya 
n = int(input())
kek = []
for i in range(1,51+1):
	for j in range(i,51+1):
		kek.append(i*j)
print(kek[n])
"""
"""
#delitsya na 4 or 8 or 2?
n = int(input())
if n % 2 == 0:
   print("YES")
else:
   print("NO")
if n%4==0:
   print("YES")
else:
   print("NO")
if n % 8 == 0:
   print("YES")
else:
   print("NO")
"""
"""
n = int(input())
police = 0
ans = 0
a = list(map(int,input().split()))
for i in range(n):
		if a[i]<0 and police != 0:
			police -= 1
		elif a[i] < 0 and police == 0:
			ans += 1
		elif a[i]>0:
			police+=a[i]			
print(ans)
"""
n = int(input())
a = list(map(int,input().split()))
b = list(set(a))
kek = len(set(a))
ans = 0
for i in range(len(b)):
	if b[i] != 0:
		ans += 1
print(ans)


