n = int(input())
a = list(map(int,input().split()))
s,f = map(int,input().split())
l = a + a
k = f - s
Som = sum(l[0:k])
indice = 0
value = 0
Max = Som
for i in range(1,n) :
	Som -= l[value]
	Som += l[i+k-1]
	value += 1
	if Som == Max :
		indice2 = i
		u2 = s-indice2
		if u2<= 0:
			u2 =n +u2

		u = s -indice
		if u <= 0 :
			u = n+ u

		if u2 <= u :
			indice = i

	if Som > Max :
		Max = Som
		indice = i

u = s - indice
if u <= 0 :
	u = n + u

print(u)
	

	

