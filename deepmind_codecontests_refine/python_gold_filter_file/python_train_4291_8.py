from sys import stdin
input = stdin.readline

def mp():return map(int,input().split())
def it():return int(input())

n=it()
s=list(input())
s=s[:n]
k=s.copy()
v=[]
for i in range(n-1):
	# print(s[i])
	if s[i]=='B' and s[i+1]=='W':
		s[i],s[i+1]=s[i+1],s[i]
		v.append(i+1)
	elif s[i]=='W':
		pass
	elif s[i]=='B' and s[i+1]=="B":
		s[i]="W"
		s[i+1]='W'
		v.append(i+1)
# print(s)

t=[]
for i in range(n-1):
	# print(s[i])
	if k[i]=='W' and k[i+1]=='B':
		k[i],k[i+1]=k[i+1],k[i]
		t.append(i+1)
	elif k[i]=='B':
		pass
	elif k[i]=='W' and k[i+1]=="W":
		k[i]="B"
		k[i+1]='B'
		t.append(i+1)

if len(set(s))==1 :
	print(len(v))
	print(*v)
elif len(set(k))==1:
	print(len(t))
	print(*t)
else:
	print(-1)
