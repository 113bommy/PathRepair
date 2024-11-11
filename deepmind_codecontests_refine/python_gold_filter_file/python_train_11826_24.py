n = int(input())
l = list(map(int, input().split()))

l.sort()

mi=abs(l[0]-l[1])
cnt=1

for i in range(1, len(l)-1):
	d = abs(l[i]-l[i+1])
	if(d < mi):
		mi = d
		cnt=1
	elif (d == mi):
		cnt += 1
	
print(mi, end=" ")
print(cnt, end="")

