x = int(input())
y = []
k = 0
l = 0
s = 0
s1 = 0
for i in range(x):
	

	y.append(list(map(int,input().split())))

for i in range(x):
		if y[i][0] == 1:


			t = y[i][1]
			s = s + t
			k = k + 1
		if y[i][0] == 2:
			g = y[i][1]
			s1 = s1 + g
			l = l + 1
if s>=5*k:


	print("LIVE")
if s<5*k:
	print("DEAD")
if s1>=5*l:
	print("LIVE")
if s1<5*l:
	print("DEAD")
