n = int(input())
a = sorted(list(map(int,input().split())))
s1 = sorted(list(map(int,input().split())))
s2 = sorted(list(map(int,input().split())))
l,r,d=0,0,[]
cnt = 0 
while r<n:
	if a[r]!=s1[l]:
		d.append(a[r])
		r+=1
		cnt+=1
	else:
		if l<n-2:
			l+=1
			r+=1
		else:
			d.append(a[r+1])
			break
	if cnt:
		break

l,r,cnt = 0,0,0

while r<n-1:
	if s1[r]!=s2[l]:
		d.append(s1[r])
		r+=1
		cnt+=1
	else:
		if l<n-3:
			l+=1
			r+=1
		else:
			d.append(s1[r+1])
			cnt+=1
	if cnt:
		break
for i in d:
	print(i)