n, x=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]

ax=[i^x for i in a]
a.sort()
ax.sort()
pos=0
posx=0
c=1
cx=1
total=0
while pos<n and posx<n:
	if a[pos]==ax[posx]:
		if pos<n-1 and a[pos+1]==a[pos]:
			pos+=1
			c+=1
		elif posx<n-1 and ax[posx+1]==ax[posx]:
			posx+=1
			cx+=1
		else:
			#print(c, cx, pos, posx)
			total+=c*cx
			c=1
			cx=1
			pos+=1
			posx+=1
	elif a[pos]>ax[posx]:
		posx+=1
	else:
		pos+=1
#print(total, a, ax)
if x>0:
	print(total//2)
else:
	print((total-n)//2)


